class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        int cnt = 0;
        int ans = 0;
        
        Node* curr = head;
        
        while(curr!=nullptr){
            cnt++;
            curr = curr->next;
        }
        
        for(int i=1; i<=cnt; i++){
            if(cnt-i<n){
                ans += head->data;
            }
            
            head = head->next;
        }
        
        return ans;
    }
};
