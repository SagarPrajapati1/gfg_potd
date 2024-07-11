class Solution {
  public:
  
  int assign(int row, int col, int n, int ind, vector<vector<int>> &v, vector<vector<int>> &grid){
        if(grid[row][col]==0 || v[row][col]!=-1) return 0;
        v[row][col]=ind;
        
        int left=0,right=0,up=0,down=0;
        if(col>0) left=assign(row,col-1,n,ind,v,grid);
        if(col<n-1) right=assign(row,col+1,n,ind,v,grid);
        if(row>0) up=assign(row-1,col,n,ind,v,grid);
        if(row<n-1) down=assign(row+1,col,n,ind,v,grid);
        
        return 1+left+right+up+down;
    }
    
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        vector<vector<int>> v(n,vector<int>(n,-1));
        vector<int> count;
        int ind=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 || v[i][j]!=-1) continue;
                int cnt=assign(i,j,n,ind,v,grid);
                count.push_back(cnt);
                ind++;
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]!=-1){
                    maxi=max(maxi,count[v[i][j]]);
                    continue;
                }
                int left=-1,right=-1,up=-1,down=-1;
                if(j>0) left=v[i][j-1];
                if(j<n-1) right=v[i][j+1];
                if(i>0) up=v[i-1][j];
                if(i<n-1) down=v[i+1][j];
                
                int sum=1;
                if(left!=-1 && left!=up && left!=right && left!=down) sum+=count[left];
                if(up!=-1 && up!=right && up!=down) sum+=count[up];
                if(right!=-1 && right!=down) sum+=count[right];
                if(down!=-1) sum+=count[down];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
        
    }


    // int solve(int i, int j, int ind, vector<vector<int>> &vis, vector<vector<int>> &grid) {
    //     if(grid[i][j] == 0 || vis[i][j] != -1) return 0;
    //     vis[i][j] = ind;
        
    //     int n = grid.size();
        
    //     int l = 0, r = 0, u = 0, d = 0;
    //     if(j > 0) l = solve(i, j-1, ind, vis, grid);
    //     if(j < n-1) r = solve(i, j+1, ind, vis, grid);
    //     if(i > 0) u = solve(i-1, j, ind, vis, grid);
    //     if(i < n-1) d = solve(i+1, j, ind, vis, grid);
        
    //     return (1 + l + r + u + d);
    // }
    // int MaxConnection(vector<vector<int>>& grid) {
    //     // code here
    //     // get all the connected component for each 1
    //     int row = grid.size();
    //     int col = grid[0].size();
        
    //     vector<vector<int>>vis(row, vector<int>(col, -1));
    
    //     int ind = 0;
        
    //     vector<int> count(row);
    //     for(int i = 0; i < row; i++) {
    //         for(int j = 0; j < col; j++) {
    //             if(grid[i][j] == 1 || vis[i][j] != -1) {
    //                 int cnt = solve(i, j, ind, vis, grid);
    //                 count.push_back(cnt);
    //                 ind++;
    //             }
    //         }
    //     }
        
        
    //     // check for each cell 0
    //     int maxi = 0;
    //     for(int i = 0; i < row; i++) {
    //         for(int j = 0; j < col; j++) {
    //             if(vis[i][j] != -1) {
    //                 maxi = max(maxi, count[vis[i][j]]);
    //                 continue;
    //             }
                
    //             int l = -1, r = -1, u = -1, d = -1; 
    //             if(j > 0) l = vis[i][j-1];
    //             if(j < row-1) r = vis[i][j+1];
    //             if(i > 0) u = vis[i-1][j];
    //             if(i < row-1) d = vis[i+1][j];
                
    //             int sum = 1;
                
    //             if(l != -1 && l != u && l != r && l != d) sum += count[l];
    //             if(r != -1 && r != d) sum += count[r];
    //             if(u != -1 && u != r && u != d) sum += count[u];
    //             if(d != -1) sum += count[d];
    //             maxi = max(maxi, sum);
                
    //         }
    //     }
    //     return maxi;
    // }
};
