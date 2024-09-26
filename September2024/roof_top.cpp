class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int cnt = 0;
        int mx = -99999;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > arr[i-1]){
                cnt++;
            }
            else {
                mx = max(mx, cnt);
                cnt = 0;
            }
            
            if(i == arr.size() - 1) {
                return max(mx, cnt);
            }
        }
        if(mx != -99999) return mx;
        return cnt;
    }
};
