class Solution {
  public:
    double maxVolume(double P, double A) {
        // code here
        double l = (double)(P - sqrt(P * P - 24 * A)) / 12;
 
        double height = (P / 4) - (2 * (l));
        
        double ans = l * l* height;
        return ans;
    }
};
