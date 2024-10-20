class Solution {
   struct Compare{
        bool operator()(DLLNode* a, DLLNode* b){
            return a->data > b->data;
        }
    };
    
public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        
        priority_queue<DLLNode*,
        vector<DLLNode*>, Compare> minHeap;
        
        DLLNode *dummy = new DLLNode(-1);
        DLLNode *newHead = dummy;
        while(head){
            if(minHeap.size() == k + 1){
                newHead->next = minHeap.top();
                minHeap.pop();
                newHead->next->prev = newHead;  
                newHead = newHead->next;
            }
            minHeap.push(head);
            head = head->next;
        }
        
        while(!minHeap.empty()){
            newHead->next = minHeap.top();
            minHeap.pop();
            newHead->next->prev = newHead;  
            newHead = newHead->next;
        }
        
        newHead->next = NULL;
        
        DLLNode *sortedList = dummy->next;
        if(sortedList){
            sortedList->prev = NULL;
        }
        
        delete dummy;
        
        return sortedList;
    }
};
