class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
      
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int minHeight = arr[0];
        int maxHeight = arr[n-1];
        
        int ans = arr[n - 1] - arr[0];
        
        for(int i = 1; i < n; i++) {
          
            if (arr[i] - k < 0) continue;
            
            minHeight = min(arr[0]+k, arr[i]-k);
            maxHeight = max(arr[i-1]+k, arr[n-1]-k);
            ans = min(ans, (maxHeight - minHeight));
        }
        
        return ans;
    }
};
