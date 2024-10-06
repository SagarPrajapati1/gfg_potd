class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        queue<pair<int, int>> q;
        int cnt = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        int delR[] = {-1, -1, -1, 1, 1, 1, 0, 0};
        int delC[] = {-1, 0, 1, -1, 0, 1, -1, 1};
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    
                    cnt++;
                    
                    q.push({i, j});
                    
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        
                        q.pop();
                        
                        
                        for(int k = 0; k < 8; k++){
                            int nr = r + delR[k];
                            int nc = c + delC[k];
                            
                            if(nr >= 0 && nr < row && nc >= 0 && nc < col && 
                            grid[nr][nc] == '1')
                            {
                                q.push({nr, nc});
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
