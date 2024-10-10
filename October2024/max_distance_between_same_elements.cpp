class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        
        unordered_map<int, pair<int, int>>mp;
        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = {i, i};
            }else{
                mp[arr[i]].second = i;
            }
        }
        
        int maxi = 0;
        for(auto m : mp){
            maxi = max(maxi, m.second.second-m.second.first);
        }
        return maxi;
    }
};
