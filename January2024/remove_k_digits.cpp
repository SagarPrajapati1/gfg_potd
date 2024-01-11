class Solution {
  public:
    string removeKdigits(string s, int k) {
        int n =s.size();
        deque<int>dq;
        for(int i=0 ;i<n;i++){
        
            while(!dq.empty() && s[i]-'0'<dq.back()&& k>0){
               dq.pop_back();
               k--;
               
            }
            dq.push_back(s[i]-'0');
        }
   
//if k>0
        while(k--){
            dq.pop_back();
        }
      
// remaining element add to ans
        string str="";
        bool leadingZero = true;
        
        for(auto x: dq){
            if(x==0 && leadingZero) continue;
            leadingZero = false;
            str+=to_string(x);
        }
        return (str=="")?"0":str; 
    }
};

// 2nd Solution
// Back-end complete function Template for C++
class Solution {
  public:
    string removeKdigits(string S, int K) {
        string ans = ""; // treat ans as a stack in below for loop

        for (char c : S) {
            while (ans.length() && ans.back() > c && K) {
                ans.pop_back(); // make sure digits in ans are in ascending
                                // order
                K--;            // remove one char
            }

            if (ans.length() || c != '0') {
                ans.push_back(c);
            } // can't have leading '0'
        }

        while (ans.length() && K--) {
            ans.pop_back();
        } // make sure remove k digits in total

        return ans.empty() ? "0" : ans;
    }
};
