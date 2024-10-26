/*
  Node is defined as
struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution {
  public:
    int count(struct Node* head, int key) {
        // add your code here
        if(head == NULL) return 0;
        int cnt = 0;
        while(head){
            if(head -> data == key) cnt++;
            head = head -> next;
        }
        return cnt;
    }
};
