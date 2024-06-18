class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int ans = 0;
        int d =2*r;
        
        for(int l = 1; l <= d; l++) {
            for(int w = 1; w <= d; w++) {
                if(l*l + w*w <= 4*r*r) ans++;
            }
        }
        return ans;
    }
};
