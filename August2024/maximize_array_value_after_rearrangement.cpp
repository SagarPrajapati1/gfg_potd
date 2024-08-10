class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(), arr.end());
         int ans = 0;
    
        int MOD = 1000000007;
        
        for(long long int i = 0; i < arr.size(); i++){
            ans = (ans + (arr[i]*i) % MOD) % MOD;
        }
        return ans % MOD;
    }
};
