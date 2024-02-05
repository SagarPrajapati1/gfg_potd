/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
      
        // when list is empty
        if(head == nullptr){
            Node* newNode = new Node(data);
            newNode -> next = newNode;
            return newNode;
        }
        
        // in the starting
        Node* newNode = new Node(data);
        Node* curr = head;
        
        if(data < head -> data){
            while(curr -> next != head) curr = curr -> next;
            curr -> next = newNode;
            newNode -> next = head;
            return newNode;
        }
        
        // insert in between or end
        while(curr -> next != head && curr -> next -> data < data) curr = curr -> next;
        
        newNode -> next = curr -> next;
        curr -> next = newNode;
        return head;
        
        
    }
};
