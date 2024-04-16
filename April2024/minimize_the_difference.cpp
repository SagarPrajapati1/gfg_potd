class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int> suffixMin(n);
        vector<int> suffixMax(n);
        int maxi = arr[n-1];
        int mini = arr[n-1];
        for(int i=n-1;i>=0;i--)
        {
            mini = min( mini, arr[i]);
            maxi = max( maxi , arr[i]);
            suffixMin[i]  = mini;
            suffixMax[i]  = maxi;
        }
        int ans = INT_MAX;
        int premax = arr[0];
        int premin = arr[0];
        // ignoring the first k elements 
        ans = min( ans , suffixMax[k] - suffixMin[k]);
        
        for(int i=1;i < n-k;i++)
        {
            int minval = min(premin , suffixMin[i+k]);
            int maxval = max(premax , suffixMax[i+k]);
            ans = min(ans , maxval - minval);
            premax = max(premax , arr[i]);
            premin = min(premin , arr[i]);

        }
        
        // ignoring the last k ements 
        ans = min(ans  , premax - premin);
        return ans;    
    }
};
