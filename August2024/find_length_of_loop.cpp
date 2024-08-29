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
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        struct Node* slow, *fast;
        slow = fast = head;
        if(head == nullptr || head -> next == nullptr)
            return 0;
            
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast) break;
        }
        
        if(fast == nullptr || fast -> next == nullptr) return 0;
        
        int cnt = 1;
        
        slow = slow -> next;
        
        while(slow != fast){
            cnt++;
            slow = slow -> next;
        }
        return cnt;
    }
};
