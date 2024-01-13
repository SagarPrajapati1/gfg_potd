class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        //code here
            function < void (Node*) > helper = [&] (Node*curr){
               if(curr == nullptr) return;
               helper(curr -> next);
               
               int val = curr->data;
               Node* next = curr->next;
               
               while(next){
                   if(next -> data < val){
                       curr -> data = next -> data;
                       curr = curr -> next;
                       next = curr -> next;
                   }
                   else break;
               }
               curr -> data = val;
           };
           helper(head);
        return head;
    }
    
};
