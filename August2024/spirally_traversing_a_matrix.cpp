class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix) 
    {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;
        int row = r;
        int col = c;
        
        int count = 0; 
        int total = row * col;
        
        // initialization
        int startRow = 0;
        int endCol = col - 1;
        int startCol = 0;
        int endRow = row - 1;
    
        while(count < total) {
            // Printing first row
            for(int index = startCol; count < total && index <= endCol; index++) {
                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;
            // Printing end Column
            for(int index = startRow; count < total && index <= endRow; index++) {
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;
            //Printing end Row
            for(int index = endCol; count < total && index >= startCol; index--) {
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;
            //Printing start Column
            for(int index = endRow; count < total && index >= startRow; index--) {
                ans.push_back(matrix[index][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
        

    }
};
