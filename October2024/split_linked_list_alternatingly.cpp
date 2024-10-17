class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        if(head==NULL && head->next==NULL) return {head};
        vector<Node*>ans;
        Node* slow=head;
        Node* fast=head->next;
        
        ans.push_back(slow);
        ans.push_back(fast);
        
        while(slow&&fast){
            slow->next=fast->next;
            slow=fast->next;
            if(fast->next){
                fast->next=fast->next->next;
                fast=fast->next;
            }
        }
        return ans;
    }
};
