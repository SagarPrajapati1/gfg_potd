class Solution {
  public: 
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        vector<int> pairs = {-1, -1};
        
        for(vector<int> & v : arr) {
            if(pairs[0] == -1){
                pairs = v;
            } else {
                if(pairs[1] >= v[0]) {
                    pairs[1] = max(pairs[1], v[1]);
                } else {
                    ans.push_back(pairs);
                    pairs = v;
                }
            }
        }
        ans.push_back(pairs);
        return ans;
    }
};
