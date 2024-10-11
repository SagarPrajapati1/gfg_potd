class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> ans(arr.size(), -1);
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] >= 0 && arr[i] < n) ans[arr[i]] = arr[i];
        }
        return ans;
    }
};
