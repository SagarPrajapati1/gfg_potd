class Solution {
    bool isPalindromeRow(int row, vector<vector<int>> arr, int n) {
        int start = 0;
        int end = n - 1;
        
        while (start <= end) {
            if (arr[row][start] != arr[row][end]) {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
    bool isPalindromeCol(int col, vector<vector<int>> arr, int m)
    {
      int start = 0;
        int end = m - 1;
        
        while (start <= end) {
            if (arr[start][col] != arr[end][col]) {
                return false;
            }
            start++;
            end--;
        }
        
        return true;  
    }
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int m = arr.size();
        int n = arr[0].size();
        string str = "";
        
        // traverse rows
        for (int i = 0; i < m; i++) {
            if (isPalindromeRow(i, arr, n)) {
                return to_string(i) + " R";
            }
        }
        
        //traverse columns
        for (int j = 0; j < n; j++) {
            if (isPalindromeCol(j, arr, m)) {
                return to_string(j) + " C";
            }
        }
        
        return "-1";
    }
};
