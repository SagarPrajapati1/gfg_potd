class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int var = n;
        int ans = 0;
        int sum = 0;
        while(var){
            int rem = var % 10;
            sum += pow(rem, 3);
            var /= 10;
            
        }
        
        if(sum == n) return "true";
        return "false";
    }
};
