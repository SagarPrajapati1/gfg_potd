class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    // using fibonacci series concept
	    long long ans = 0;
	    int next = 1;
	    int prev = 1;
	    
	    for(int i = 1; i <= N; i++) {
	        ans = (prev+next)%1000000007;
	        prev = next;
	        next = ans;
	    }
	    
	    ans = (ans*ans)%1000000007;
	    
	    return (int)ans;
	    
	}
};
