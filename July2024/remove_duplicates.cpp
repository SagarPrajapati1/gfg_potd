class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        string ans;
        unordered_map<char, int> mp;
        int n = str.size();
        for(int i=0; i<n; i++){
            int sz = mp.size();
            mp[str[i]]++;
            if(sz != mp.size()){
                ans += str[i];
            }
        }
        return ans;
    }
};
