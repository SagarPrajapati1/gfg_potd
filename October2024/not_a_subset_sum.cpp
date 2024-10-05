class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        long long ans = arr[0];
        if(arr[0] != 1 ) return 1;
        
        for(int i = 1; i < arr.size(); i++) {
            if(ans + 1 >= arr[i]) ans += arr[i];
            else return ans+1;
        }
        return ans+1;
    }
};
