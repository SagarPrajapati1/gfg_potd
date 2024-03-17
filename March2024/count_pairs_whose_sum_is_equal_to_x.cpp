/*
Structure of the node of the linked list is as
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
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int sum) {
        // Code here
       unordered_map<int, int> st;
       // set takes O(logn) time but map takes O(1) time to search
        
        Node* temp1 = head1;
        while(temp1){
            st[temp1 -> data] = 1;
            temp1 = temp1 -> next;
        }
        
        int cnt = 0;
 
        Node*temp2 = head2;
        
        while(temp2 != nullptr){
            if(st.find(sum-temp2 -> data) != st.end()) cnt++;
            temp2 = temp2 -> next;
        }
        return cnt;
    }
};
