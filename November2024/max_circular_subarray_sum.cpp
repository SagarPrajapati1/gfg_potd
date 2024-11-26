class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &nums) {

        int n = nums.size();
        
        // Step 1: Find maximum subarray sum using standard Kadane's algorithm
        int maxKadane = INT_MIN, currentMax = 0;
        
        // Step 2: Find the minimum subarray sum (for circular case)
        // Because we will erase the middle part and take the circular part around it
        int minKadane = INT_MAX, currentMin = 0, totalSum = 0;
        
        for (int i = 0; i < n; i++) {
            currentMax = max(nums[i], currentMax + nums[i]);
            maxKadane = max(maxKadane, currentMax);
            
            currentMin = min(nums[i], currentMin + nums[i]);
            minKadane = min(minKadane, currentMin);
            
            totalSum += nums[i];
        }
        
        // Step 3: Handle the case where all elements are negative
        if (maxKadane < 0) return maxKadane;
        
        // Step 4: Calculate the maximum of non-circular and circular cases
        return max(maxKadane, totalSum - minKadane);
    }
};
