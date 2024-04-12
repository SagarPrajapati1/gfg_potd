class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long ans = 0;
        vector<int> temp(32, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 32; j++){
                if(arr[i] & (1 << j)){
                    ans += temp[j]*(1LL << j);
                    temp[j]++;
                }
            }
        }
        return ans;
    }
};
