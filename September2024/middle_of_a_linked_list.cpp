/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        if(head == NULL) return 0;
        
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow -> data;
    }
};
