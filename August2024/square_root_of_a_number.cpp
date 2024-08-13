class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int s = 0;
        long long int e = n;
        long long int ans = -1;
        
        while(s <= e) {
            long long int mid = e - (e-s)/2;
            long long int sq = mid * mid;
            if(sq <= n) {
                ans = mid;
                s = mid + 1;
            }
            
            else e = mid-1;
        }
        return ans;
    }
};
