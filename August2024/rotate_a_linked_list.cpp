/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        
        // Your code here
        
        if(head == NULL) return NULL;
        
        Node* h1 = head;
        Node* h2 = head;
        Node*temp = head;
        while(head -> next){
            head = head -> next;
        }
        // cout << head -> data << endl;
        head -> next = temp;
        while(k > 1){
            temp = temp -> next;
            k--;
        }
        
        h1 = temp -> next;
        // cout << h1 -> data << endl;
        
        temp -> next = nullptr;
        
        return h1;
    }
};
