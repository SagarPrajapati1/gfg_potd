class Solution
{
    public:
       struct Node * reverse(Node *root){
        Node* prev = NULL;
        Node* curr = root;
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        // Node *head1 = reverse(node1);
        // Node *head2 = reverse(node2);
        
        Node *temp1 = node1;
        Node *temp2 = node2;
        Node *newHead = new Node();
        Node *res = newHead;
        
        while(temp1 && temp2) {
            
            if(temp1 -> data <= temp2 -> data) {
                res -> next = temp1;

                temp1 = temp1 -> next;
            }
            
            else {
                
                res -> next = temp2;
               
                temp2 = temp2 -> next;
            }
            res = res-> next;
        }
        

            while(temp1) {
                res -> next = temp1;
                res = res -> next;
                temp1 = temp1 -> next;
            }

            while(temp2) {
                res -> next = temp2;
                res = res -> next;
                temp2 = temp2 -> next;
            }
        
        return reverse(newHead -> next);
    }  
};
