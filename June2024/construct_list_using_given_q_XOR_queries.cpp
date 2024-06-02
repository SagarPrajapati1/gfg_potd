class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here\
        // Time Limit Exceed
        // vector<int> ans;
        // ans.push_back(0);
        // for(int i = 0; i < queries.size(); i++){
        //     int first = queries[i][0];
        //     int second = queries[i][1];
            
        //     if(first == 0) ans.push_back(second);
        //     else if(first == 1) {
        //         for(int j = 0; j < ans.size(); j++){
        //             ans[j] = ans[j] ^ second;
        //         }
        //     }
        // }
        
        // sort(ans.begin(), ans.end());
        // return ans;
        
        vector<int> ans;
        ans.push_back(0);
        int xorr = 0;
        
        for (auto &it : queries) {
            if(it[0] == 0) {
                ans.push_back(it[1]^xorr);
            }
            else {
                xorr ^= it[1];
            }
        }
        
        for(auto &it : ans){
            it ^= xorr;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
