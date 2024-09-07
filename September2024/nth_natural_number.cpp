class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        if(n < 9) return n;
        if( n == 9) return 10;
        
        long long res = 0;
        long long val = 1;
        
        while(n > 0){
            long long rem = n%9;
            res = res + rem * val;
            n /= 9;
            val *= 10;
        }
        return res;
    }
};
