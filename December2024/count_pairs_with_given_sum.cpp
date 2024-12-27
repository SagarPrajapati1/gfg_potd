class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        
        int cnt = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            int sum = target - arr[i];
            
            if(mp.find(sum)  != mp.end()) cnt += mp[sum];
            
            mp[arr[i]]++;
        }
        return cnt;
    }
};
