class Solution{
public:
    long long sequence(int n){
        long long MOD = 1e9+7;
        // code here
        long long prev = 1;
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            int j = 1;
            long long var = 1;
            
            while(j <= i) {
                var = (var % MOD * prev % MOD) % MOD;
                prev++;
                j++;
            }
            
            ans = (ans + var) % MOD;
        }
        return ans;
    }
};
