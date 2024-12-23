class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        for(int i = 0; i < mat.size(); i++) 
        {
            int s = 0; int e = mat[i].size() - 1;
            while(s <= e){
                int mid = (s+e)/2;
                if(mat[i][mid] == x) return true;
                else if(mat[i][mid] > x) e = mid - 1;
                else s = mid + 1;
            }
        }
        
        return false;
    }
};
