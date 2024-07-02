/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string str = "";
        
        Node* temp = head;
        if(!head) return false;
        
        while(temp){
            str += temp -> data;
            temp = temp -> next;
        }
        string s = str;
        reverse(str.begin(), str.end());
        return str == s;
    }
};
