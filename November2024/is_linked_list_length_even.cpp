
/*structure of a node of the linked list is as
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
class Solution {
  public:
    bool isLengthEven(struct Node **head) {
         int cnt = 0;
        // if(!head) return 1;
        // if(!head -> next) return 0;
        Node *temp = *head;
        
        while(temp != nullptr){
            cnt++;
            temp = temp -> next;
        }
        return cnt % 2 == 0 ? 1 : 0;
    }
};
