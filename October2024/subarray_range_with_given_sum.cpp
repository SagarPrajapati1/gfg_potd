class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        
        int curr = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            curr = curr += arr[i];
            if(curr == tar) ans++;
            if(mp.end() != mp.find(curr - tar)) ans += mp[curr-tar];
            mp[curr]++;
        }
        return ans;
    }
};
