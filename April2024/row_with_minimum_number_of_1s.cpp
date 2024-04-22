class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here1
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                cnt += (a[i][j] == 1) ;
            }
            
            if(mini > cnt){
                mini = cnt;
                ans = i+1;
            }
        }
        return ans;
        
    }
};
