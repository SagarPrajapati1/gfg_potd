class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans=-1;
        for(int i=0;i<n-1;i++){
            int sum = arr[i]+arr[i+1];
            ans = max(sum,ans);
        }
        return ans;
    }
};
