class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& matrix) {
        // code here
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
         }
         
        for(int i = 0; i < n; i++){
            int a = 0;
            int b = n-1;
            while(a < b){
                swap(matrix[a++][i], matrix[b--][i]);
            }
        }
    }
};
