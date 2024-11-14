class Solution {
  public:
    void nearlySorted(vector<int>& num, int K) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<int> ans;
        
        for(int i = 0; i < num.size(); i++) {
            pq.push(num[i]);
            
            if(pq.size() == K + 1) {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        
        // for(int i = 0; i < num; i++){
        //     pq.push(arr[i]);
        // }
        
        // vector<int> ans;
        // while(!pq.empty()) {
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        
        num.clear();
        for(auto i : ans) num.push_back(i);
    }
};
