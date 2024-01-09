class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> ans;
            
            int m = pat.size();
            int n = txt.size();
            
            
            for(int i = 1; i <= n-m+1; i++) {
                
                int f = i-1;
                int s = 0;
                
                while(s < m) {
                    if(pat[s] != txt[f]) break;
                    else {
                        f++;
                        s++;
                    }
                }
                
                if(s == m) ans.push_back(i);
            }
            
            if(ans.size() > 0) return ans;
            else return {-1};
        }
     
};
