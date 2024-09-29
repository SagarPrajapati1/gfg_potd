class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        // code here
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            int val = arr[i]/k;
            ans += val;
            if(arr[i]%k) ans += 1;
        }
        return ans;
    }
};
