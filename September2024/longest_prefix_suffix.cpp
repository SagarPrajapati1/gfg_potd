// User function template for C++

class Solution {
  public:
    int lps(string s) {
        int pre = 0;
	    int suf = 1;
	    
	    int n = s.size();
	    vector<int> LPS(n,0);
	    
	    while(suf < n){
	        // match
	        if(s[pre] == s[suf])
	        {
	            LPS[suf] = pre+1;
	            pre++;
	            suf++;
	        }
	        
	        // not match
	        else {
	            // prefix = 0;
	            if(pre == 0){
	                LPS[suf] = 0;
	                suf++;
	            }
	            else {
	                pre = LPS[pre-1];
	            }
	        }
	    }
	    return LPS[n-1];
    }
};
