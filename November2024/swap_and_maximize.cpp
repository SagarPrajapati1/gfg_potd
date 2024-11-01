class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        
        
        sort(begin(arr), end(arr));
        
        long long ans = 0;
        int n = arr.size();
        
        int s = 0, e = n-1;
        
        while(s < e) {
            ans += abs(arr[e] - arr[s]) + abs(arr[e] - arr[s+1]);
            s++;
            e--;
        }
        ans += abs(arr[s] - arr[0]);
        return ans;
    }
};
