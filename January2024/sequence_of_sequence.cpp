class Solution {
public:
    // Function to find the number of sequences
    int numberSequence(int m, int n)
    {

        int dp[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                // Base case : If length of sequence is 0
                // or maximum value is 0, there cannot
                // exist any special sequence
                if (i == 0 || j == 0)
                    dp[i][j] = 0;

                // if length of sequence is more than
                // the maximum value, special sequence
                // cannot exist
                else if (i < j)
                    dp[i][j] = 0;

                // If length of sequence is 1 then the
                // number of special sequences is equal
                // to the maximum value
                // For example with maximum value 2 and
                // length 1, there can be 2 special
                // sequences {1}, {2}
                else if (j == 1)
                    dp[i][j] = i;

                // otherwise calculate
                else
                    dp[i][j]
                        = dp[i - 1][j] + dp[i / 2][j - 1];
            }
        }
        return dp[m][n];
    }
};


// 2nd solution
class Solution{
public:
    int solve(int i, int m, int n) {
        if(n == 0) return 1;
        
        if(m < 0 || i > m) {
            return 0;
        }
        
        return solve(i+1, m, n) + solve(2*i, m, n-1);
    }
    int numberSequence(int m, int n){
        // code here
        return solve(1, m, n);
    }
};
