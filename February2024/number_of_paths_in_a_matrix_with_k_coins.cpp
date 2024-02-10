class Solution {
public:
    long long dp[101][101][101];
    
    long long solve(int i, int j, int n, int k, vector<vector<int>> &arr) {
        
        // check if indices arr within range and k is not less then 0
        if(i >= n || j >= n || k < 0) return 0ll;
        
        
        // check if i and j are on the boundary and sum is zero 
        if(i == n-1 && j == n-1 && k-arr[i][j] == 0) return 1ll;
        
        // check if the sum is already exist
        if(dp[k][i][j] != -1) return dp[k][i][j];
        
        // check for both condition
        return dp[k][i][j] = solve(i, j+1, n, k-arr[i][j], arr) + solve(i+1, j, n, k-arr[i][j], arr);
    }
    
    
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        memset(dp, -1, sizeof(dp));
        return solve(0ll, 0ll, n, k, arr);
        
    }
};
