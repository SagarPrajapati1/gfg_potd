class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        Node*t1=NULL,*t2=NULL,*temp=head;
        bool start=true;
        while(start || head!=temp) {
        t2=head->next;
        head->next=t1;
        t1=head;
        head=t2;
        start=false;
        }
        temp->next=t1;
        return t1;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        Node*prev=head;
        Node*curr=head->next;
        while(curr && curr!=head){
         if(prev->data==key){
           while(curr->next!=head) curr=curr->next;
           curr->next=head->next;
           head=head->next;
           return head;
         } 
         else{
           if(curr->data==key){
             prev->next=curr->next;
             return head;
           }
           prev=curr;
           curr=curr->next;
         }
        }
        return head;
        
        
    }
};
