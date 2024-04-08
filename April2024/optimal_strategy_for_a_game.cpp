//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long dp[1001][1001];
    
    long long helper(int arr[],int i,int j,int n)
    {
        if(i>=n or j<0 or j-i+1<=0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        long long d1 = arr[i]+min(helper(arr,i+2,j,n),helper(arr,i+1,j-1,n));
        
        long long d2 = arr[j]+min(helper(arr,i+1,j-1,n),helper(arr,i,j-2,n));
        
        return dp[i][j]=max(d1,d2);
    }
    
    long long maximumAmount(int n, int arr[]){
        // Your code here
        memset(dp,-1,sizeof(dp));
        return helper(arr,0,n-1,n);
    }
};
