class Solution{
	public:
    vector<string> ans;
    void solve(string s, int ind, string tempS) {
        if(ind == s.length()) {
            if(tempS != "") ans.push_back(tempS);
            return;
        }
        
        solve(s, ind+1, tempS);
        solve(s, ind+1, tempS+s[ind]);
    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		   
		    solve(s, 0, "");
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
