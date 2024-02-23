class Solution
{
    public:
        int solve(int n){
            if(n == 0|| (n/2+n/3+n/4) < n) return n;
            
            int sum = solve(n/2) + solve(n/3) + solve(n/4);
        
            return sum;
        }
    
        int maxSum(int n)
        {
            //code here
            return solve(n);

        }
};
