class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here+
        
        int row = mat.size();
        int col = mat[0].size();
        
        int n = row*col;
        int cnt = 0;
        
        int firstRow = 0;
        int lastCol = col - 1;
        
        int lastRow = row - 1;
        int firstCol = 0;
        
        vector<int> ans;
        
        while(cnt < n) {
            // top row
            
            for(int i = firstCol; i <= lastCol && cnt < n; i++){
                ans.push_back(mat[firstRow][i]);
                cnt++;
            }
            firstRow++;
            // last col
            for(int i = firstRow; cnt < n && i <= lastRow; i++){
                ans.push_back(mat[i][lastCol]);
                cnt++;
            }
            lastCol--;
            
            // bottom row
            for(int i = lastCol; cnt < n && i >= firstCol; i--){
                ans.push_back(mat[lastRow][i]);
                cnt++;
            }
            lastRow--;
            
            // first col
            for(int i = lastRow; cnt < n && i >= firstRow; i--){
                ans.push_back(mat[i][firstCol]);
                cnt++;
            }
            firstCol++;
        }
        return ans;
    }
};
