class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == target) ans++;
        }
        return ans;
    }
};
