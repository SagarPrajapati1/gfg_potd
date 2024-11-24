class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
         long long sum = 0;
        int maxi = INT_MIN;
        
        int start = 0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            // if (sum == 0) start = i;
            
            sum = sum + arr[i];
            
            if(sum > maxi ){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};
