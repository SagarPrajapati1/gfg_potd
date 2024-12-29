class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        set<int> st, st1;
        
        
        for(int i = 0; i < a.size(); i++) {
            st.insert(a[i]);
        }
        
        for(int i = 0; i < b.size(); i++) {
            if(st.find(b[i]) != st.end()) st1.insert(b[i]);
        }
        
        vector<int> ans(st1.begin(), st1.end());
        
        return ans;
    }
};
