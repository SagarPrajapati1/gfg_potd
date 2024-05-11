class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> ans;
        ans.push_back(n);
        
        while(n>1){
            if(n % 2 == 0){
                long long val = sqrt(n);
                ans.push_back(val);
                n = val;
            }
            else {
                long long val = n*sqrt(n);
                ans.push_back(val);
                n = val;
            }
        }
        return ans;
    }
};
