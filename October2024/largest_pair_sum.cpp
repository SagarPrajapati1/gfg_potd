class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int mx = INT_MIN, smx = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > mx) {
                smx = mx;
                mx = arr[i];
            }
            else if(smx < arr[i]) {
                smx = arr[i];
                
            }
        }
        
        return mx + smx;
    }
};
