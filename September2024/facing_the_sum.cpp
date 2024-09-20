class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int ans = 1;
        int mx = height[0];
        for(int i = 1; i < height.size(); i++) {
            if(height[i] > mx) {
                ans++;
                mx = height[i];
            }
        }
        return ans;
        
    }
};
