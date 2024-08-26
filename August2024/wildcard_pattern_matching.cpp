class Solution {
  public:
    /*You are required to complete this method*/
    vector<vector<int>>dp;
    bool check(string &s1,string &s2,int idx1,int idx2){
        
        for(int i=idx2;i<s2.length();i++){
            if(s2[i]=='*') continue;
            else return false;
        }
        return true;
    }
    bool help(string &s1,string &s2,int idx1,int idx2 ){
        if(idx1==s1.length()) return check(s1,s2,idx1,idx2);
        if( idx2==s2.length()) return false;
        int &ans=dp[idx1][idx2];
        if(ans!=-1) return ans;
        if(s1[idx1]==s2[idx2]) return ans=help(s1,s2,idx1+1,idx2+1);
        else if(s2[idx2]=='?') return ans= help(s1,s2,idx1+1,idx2+1);
        else if(s2[idx2]=='*'){
            
            bool flag1=help(s1,s2,idx1+1,idx2+1);
            bool flag2=help(s1,s2,idx1+1,idx2);
            bool flag3=help(s1,s2,idx1,idx2+1);
            return ans=flag1|flag2|flag3;
        }
        
        
        
    }
    int wildCard(string pattern, string str) {
      
       swap(pattern,str);
        int n=pattern.length();
        int m=str.length();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return help(pattern,str,0,0);
        
        
    }
};
