class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
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


bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int tot = row*col -1;
        int s = 0;
        int e = tot;
        while(s<=e){
            int mid = s+(e-s)/2;
            int rIdx = mid/col;
            int cIdx = mid%col;
            if(mat[rIdx][cIdx] == x) return true;
            else if(mat[rIdx][cIdx] < x) s=mid+1;
            else e=mid-1;
        }
        
        return false;
    }
