class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int small = arr[0];
        int pSmall = small;
        int sSmall = 1e9;
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > sSmall){
                return {pSmall, sSmall, arr[i]}; 
            }
            else if(arr[i] < small){
                small = arr[i];
            }
            else if(arr[i] < sSmall && arr[i] > pSmall) {
                sSmall = arr[i];
            }
            else if(arr[i] > small) {
                pSmall = small;
                sSmall = arr[i];
            }
        }
        return {};
    }
};
