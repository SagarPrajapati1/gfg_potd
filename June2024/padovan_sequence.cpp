class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        if(n == 0 || n == 1 || n == 2) return 1;
        int first = 1, second = 1, third = 1, fourth;
        int mod = 1e9 + 7;
        
        while((n--)-2) {
            fourth = (first + second) % mod;
            first = second;
            second = third;
            third = fourth;
            
        }
        return fourth;
    }
};
