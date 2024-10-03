class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        vector<int> ans;
        int c1 = 0, c2 = 0;
        int r1 = nums[0];
        int r2 = nums[0];
        
        
        for(int i = 0; i < nums.size(); i++) {
            if(r1 == nums[i]) c1++;
            else if(r2 == nums[i]) c2++;
            else if(c1 == 0){
                r1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                r2 = nums[i];
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        c1 = c2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(r1 == nums[i]) c1++;
            else if(r2 == nums[i]) c2++;
        }
        
        
        if(c1 > nums.size()/3) ans.push_back(r1);
        if(c2 > nums.size()/3) ans.push_back(r2);
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};
