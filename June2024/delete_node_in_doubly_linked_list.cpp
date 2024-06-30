/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        
        if(x==1) return head->next;
        if(head==NULL || x<=0) return head;
        Node *temp= head, *cur=head; 
        while(x>1){
            temp=temp->next;
            x--;
        }
        cur=temp->prev;
       
        cur->next=temp->next;
         if(temp->next)
        temp->next->prev=cur;
        
        return head;
        
    }
};
