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

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        // if(head == NULL) return head;
        // int len = 0;
        // Node* temp = head;
        // while(temp) len++, temp = temp -> next;
        
        // if(len == 1) return NULL;
        
        // temp = head;
        // int cnt = len / 2;
        // while(cnt--) temp = temp -> next;
        // // cout << temp -> data;
        // int i = len/2-1;
        // Node* temp1 = head;
        // while(i--) temp1 = temp1 -> next;
        
        // temp1 -> next = temp -> next;
        
        // return head;
        
        Node* slow = head;
        Node* fast = head;
        Node* temp = head;
        
        if(head -> next == NULL) {
            delete head;
            return NULL;
        }
        
        
        while(fast && fast -> next){
            fast = fast -> next -> next;
            temp = slow;
            slow = slow -> next;
        }
        
        temp -> next = slow -> next;
        return head;
   
        
    }
};
