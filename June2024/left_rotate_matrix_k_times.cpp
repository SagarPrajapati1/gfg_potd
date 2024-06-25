class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
         int m=mat[0].size();
        int n=mat.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        k %= m;
        if(k == 0)
            return mat;
        for(int i=0;i<n;i++)
        {
            int x=0;
            for(int j=k;j<m;j++)
            {
                ans[i][x]=mat[i][j];
                x++;
            }
            
            for(int j=0;j<k;j++)
            {
                ans[i][x]=mat[i][j];
                x++;
            }
        }
        
        return ans;
    }
};
