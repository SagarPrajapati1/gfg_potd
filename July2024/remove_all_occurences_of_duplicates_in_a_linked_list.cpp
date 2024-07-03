/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        vector<int> arr;
        Node* temp = head;
        if(!head) return head;
        
        while(temp){
            arr.push_back(temp -> data);
            temp = temp -> next;
        }
        
        int n = arr.size();
        vector<bool> vis(n, 0);
        
        Node* h1 = new Node(-1);
        temp = h1;
        
        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1] && vis[i-1] == 0) {
                temp -> next = new Node(arr[i-1]);
                temp = temp -> next;
            }
            else if(arr[i] == arr[i-1]) {
                vis[i-1] = 1;
                vis[i] = 1;
            }
        }
        
        if(vis[n-1] == 0) {
            temp -> next = new Node(arr[n-1]);
        }
        return h1 -> next;
    }
};




//Back-end complete function Template for C++

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // create a dummy node
        // that acts like a fake
        // head of list pointing
        // to the original head
        Node* dummy = new Node(-1);

        // dummy node points
        // to the original head
        dummy->next = head;

        // Node pointing to last
        // node which has no duplicate.
        Node* prev = dummy;

        // Node used to traverse
        // the linked list.
        Node* current = head;

        while (current != NULL) {
            // Until the current and
            // previous values are
            // same, keep updating current
            while (current->next != NULL && prev->next->data == current->next->data)
                current = current->next;

            // if current has unique value
            // i.e current is not updated,
            // Move the prev pointer to
            // next node
            if (prev->next == current)
                prev = prev->next;

            // when current is updated
            // to the last duplicate
            // value of that segment,
            // make prev the next of current
            else
                prev->next = current->next;

            current = current->next;
        }

        // update original head to
        // the next of dummy node
        head = dummy->next;
        return head;
    }
};
