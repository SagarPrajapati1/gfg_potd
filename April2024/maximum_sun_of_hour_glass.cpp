class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
         int ans =  -1 ;
        
        for( int i = 1 ; i < n-1 ; i++ )
        {
            for( int j = 1 ; j < m-1 ; j++ )
            {
                int t = mat[i][j] + mat[i-1][j] + mat[i-1][j-1] + mat[i-1][j+1] + mat[i+1][j] + mat[i+1][j-1] + mat[i+1][j+1]  ;
                 ans = max( ans , t ) ;
            }
        }
        
        return ans ;
    }
};
