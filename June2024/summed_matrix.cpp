class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        // int cnt = 0;
        // int i = 1;
        
        // if(q > 2*n) return 0;
        
        
        // while(i <= n) {
        //     int j = 1;
        //     while(j <= n) {
        
        //         if(i+j == q) cnt++;
        //         j++;
        //     }
        
        //     i++;
        // }
        // return cnt;
        if(q<2 || q>2*n) return 0;
        
        long long diff = abs(n-q);
        
        if(q==n+1) return n;
        
        else if(q<=n){
            return n-diff-1;
        }
        else if(q>n+1){
            return n-diff+1;
        }
    }
};
