class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        
        priority_queue<pair<int, int>> p;
        for(int i = 0; i < n; i++){
            int diff=abs(arr[i]-x);
            if(diff!=0) p.push(make_pair(-diff,arr[i]));
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
        
    }
};
