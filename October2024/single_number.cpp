class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int xorrr = 0;
        for(auto num : arr){
            xorrr ^= num;
        }
        return xorrr;
    }
};
