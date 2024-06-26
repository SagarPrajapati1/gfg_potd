class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int cnt = 0;
        
        int delR[] = {-1, 0, 1, 0};
        int delC[] = {0, 1, 0, -1};
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0 && vis[i][j] == 0) {
                    
                    for(int k = 0; k < 4; k++) {
                        
                        int nr = i + delR[k];
                        int nc = j + delC[k];
                        
                        vis[i][j] = 1;
                        
                        if(nr >= 0 && nr < row && nc >= 0 && nc < col && matrix[nr][nc] == 1) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};


class Solution {
  public:
    // Function to find the number of cells with a value of 0 adjacent to a cell with a
    // value of 1 in a binary matrix.
    int findCoverage(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size();        // getting the number of rows in the matrix.
        int m = matrix[0].size();     // getting the number of columns in the matrix.
        for (int i = 0; i < n; i++) { // iterating over each row.
            for (int j = 0; j < m; j++) { // iterating over each column.
                if (matrix[i][j] == 1) // if the current cell has a value of 1, continue
                                       // to the next iteration.
                    continue;
                if (i - 1 >= 0 and matrix[i - 1][j]) // checking if the cell above the
                                                     // current cell has a value of 1.
                    ans++; // incrementing the count of adjacent cells.
                if (i + 1 < n and matrix[i + 1][j]) // checking if the cell below the
                                                    // current cell has a value of 1.
                    ans++; // incrementing the count of adjacent cells.
                if (j - 1 >= 0 and
                    matrix[i][j - 1]) // checking if the cell to the left of the current
                                      // cell has a value of 1.
                    ans++;            // incrementing the count of adjacent cells.
                if (j + 1 < m and
                    matrix[i][j + 1]) // checking if the cell to the right of the
                                      // current cell has a value of 1.
                    ans++;            // incrementing the count of adjacent cells.
            }
        }
        return ans; // returning the total count of adjacent cells with a value of 0.
    }
};








