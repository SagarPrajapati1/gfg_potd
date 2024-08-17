class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        vector<long long int> ans;
        long long int pre = 1;
        long long int suf = 1;
        int zero = 0;
        for(long long int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0){
                pre = pre * nums[i];
            }
            else zero++;
        }
        if(zero == 1){
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0){
                    ans.push_back(pre);
                }else ans.push_back(0);
            }
        }
        else if(zero > 1){
            for(int i = 0; i < nums.size(); i++) {
                ans.push_back(0);
            }
        }
        else {
            
            for(int i = 0; i < nums.size(); i++) {
                ans.push_back(pre/nums[i]);
            }
            
        }
        return ans;
    }
};
