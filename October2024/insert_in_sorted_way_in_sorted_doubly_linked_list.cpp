/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node *n = new Node;
        n->data = x;
        n->prev = NULL;
        n->next = NULL;
        
        Node*pre=NULL;
        Node*curr=head;
        if(curr->data>=x)
        {
            
            n->next=curr;
            return n;
        }
        while(curr!=NULL)
        {
            if(curr->data<=x)
            {
                pre=curr;
                curr=curr->next;
            }
            else{
                break;
            }
        }
        pre->next=n;
        pre=pre->next;
        pre->next=curr;
        return head;
    }
};
