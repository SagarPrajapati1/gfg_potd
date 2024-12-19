class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        int i = -1;
        while(s <= e) {
            int mid = (s+e)/2;
            
            int val = arr[mid] - mid - 1;
            
            if(val < k){
                i = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        
        int ans = arr[i] - i - 1;
        return arr[i] + k - ans;
    }
};
