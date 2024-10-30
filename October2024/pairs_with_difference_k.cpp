class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int cnt = 0;
       
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        for(int num : arr){
            int t = num + k;
            if(mp[t] > 0){
                cnt += mp[t];
            }
        }
        
        return cnt;
    }
};
