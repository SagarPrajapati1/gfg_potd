class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        
        stack<pair<char, int>> st;
        vector<int> ans;
        int cnt = 0;
        
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(') {
                cnt++;
                st.push({str[i], cnt});
                ans.push_back(cnt);
            } else if(str[i] == ')') {
                ans.push_back(st.top().second);
                st.pop();
            }
        }
        
        return ans;
    }
};
