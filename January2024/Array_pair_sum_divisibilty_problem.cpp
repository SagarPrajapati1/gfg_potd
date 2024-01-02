class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n % 2 != 0 ) return false;
        
        vector<int> count(k+1, 0);
        for(auto var : nums){
            var = var % k;
            count[var]++;
            count[k-var]--;
        }
        
        for(int i = 1; i < k; i++) {
            if(count[i] > 0) return false;
        }
        
        return true;
    }
};
