class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        set<vector<int>> resSet;
        unordered_map<int, vector<pair<int, int>>> mp;
        
        int n = arr.size();
        
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                mp[arr[i] + arr[j]].push_back({i, j});
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (mp.count(-arr[i])) {
                for (auto &p : mp[-arr[i]]) {
                    if(p.first == i || p.second == i) continue;
                    
                    vector<int> curr = {p.first, p.second, i};
                    sort(begin(curr), end(curr));
                    resSet.insert(curr);
                }
            }
        }
        
        vector<vector<int> > res(begin(resSet), end(resSet));
        
        
        return res;
 
    }
};
