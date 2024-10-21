class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        int t_xor = 0 ;
        for(auto i : arr) t_xor ^= i;
        
        if(t_xor != 0) return 0;
        int MOD = 1e9 + 7;
        int n = arr.size();
        int ans = (pow(2, n-1) - 1);
        ans = ans  % MOD;
        return (int)ans;
    }
};
