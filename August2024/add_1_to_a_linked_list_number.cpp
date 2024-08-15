/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node *reverse (Node *head) {
        Node *curr = head;
        
        Node *prev = NULL;
        Node *forward = head;
        
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
    
    
    Node* addOne(Node *head) 
    {
        
        
        Node *revHead = reverse(head);
        Node *temp = revHead;
        
        int carry = 1;
        while(temp){
            int sum = temp -> data + carry;
        
            temp -> data = sum % 10;
            carry = sum / 10;
            if(carry && temp -> next == NULL){
                temp -> next = new Node(carry);
                break;
            }
            
            temp = temp -> next;
            
        }
        return reverse(revHead);
    }
};
