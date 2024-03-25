class Solution{
public:	
    void solve(int n, vector<string>& ans, string temp, char ch) {
        
        temp.push_back(ch);
        if(temp.length() == n){
            ans.push_back(temp);
            return;
        }
        
        int ones = 0;
        int zeros = 0;
        for(auto i : temp){
            if(i == '1') ones++;
            else  zeros++;
        }
        
        if(ones > zeros){
            solve(n, ans, temp, '0');
            solve(n, ans, temp, '1');
        }
        else solve(n, ans, temp, '1');
    }
    
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string temp = "";
	    solve(n, ans, temp, '1');
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};
