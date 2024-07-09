// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        
        
        int ans = -1;
        int min = INT_MAX;
        
        for(int i = 0; i < arr.size(); i++) {
            int j = i+1;
            int k = arr.size() - 1;
            int sum = 0;
            
            
            while(j < k) {
                
                sum = arr[i] + arr[j] + arr[k];
                int diff = abs(sum - target);
                
                if(diff == min) ans = max(ans, sum);
                
                else if(diff < min) {
                    
                    min = diff;
                    ans = sum;
                }
                
                if(sum > target) k--;
                
                else if(sum == target) return target;
                
                else j++;
            }
        }
        return ans;
    }
};
