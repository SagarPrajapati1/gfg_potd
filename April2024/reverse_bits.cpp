class Solution {
  public:
    long long reversedBits(long long X) {
        // code here
        int bits = 31;
        long result = 0;
        long long x = X;
        while(x > 0){
            
            if(x % 2 != 0) result += pow(2, bits);
            
            x /= 2;
            bits--;
        }
        return result;
    }
};
