class Solution{
public:
    int solve(int l, int r, string& str,vector<vector<int>>&dp){
    
        if(l>=r)return 0;
    
        if(dp[l][r] != -1)return dp[l][r];
    
        if(str[l] == str[r])return dp[l][r]= solve(l+1, r-1, str,dp);
    
        return dp[l][r] = min(solve(l+1 , r , str,dp),solve(l,r-1,str,dp))+1;                       
    
    }
    
    int kPalindrome(string str, int n, int k){
    
        vector<vector<int>> dp(n, vector<int>(n, -1));
    
        return k >= solve(0,n-1,str,dp);

    }
};
