/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node * merge(struct Node* n1, struct Node* n2) {
        struct Node *head = new Node(0);
        struct Node* tail = head;
        while (n1 && n2) {
            if (n1->data <= n2->data) {
                tail->next = n1;
                n1->prev = tail;
                n1 = n1->next;
            } else {
                tail->next = n2;
                n2->prev = tail;
                n2 = n2->next;
            }
            tail = tail->next;
        }
        if (n1) {
            tail->next = n1;
            n1->prev = tail;
        }
        if (n2) {
            tail->next = n2;
            n2->prev = tail;
        }
        head = head->next;
            head->prev = NULL;
        return head;
    }

    
    struct Node *sortDoubly(struct Node *head) {
       if(!head || !head->next) return head;
        struct Node * slow, *fast, *temp;
        slow = head;
        fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        slow->prev->next = NULL;
        head = sortDoubly(head);
        slow = sortDoubly(slow);
        return  merge(head, slow);
    
    }
};
