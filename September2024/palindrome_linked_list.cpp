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
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        
        if(head == NULL){
            return false;
        }
        Node *temp = head;
        vector<int> vec;
        while(temp != NULL){
            vec.push_back(temp->data);
            temp = temp -> next;
        }
        
        int size = vec.size();
        int s = 0;
        int e = size - 1;
        while(s <= e){
            if(vec[s] != vec[e]){
                return false;
            }
            else {
                s++;
                e--;
            }
            
        }
        return true;
    }
};
