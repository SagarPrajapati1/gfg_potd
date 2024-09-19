class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int j = str.length()-1;
        
        string ans = "";
        while(j >= 0) {
            string s = ""; 
            while(j >= 0 && str[j] != '.'){
            
                s+= str[j];
                j--;
            }
            if(s.length() > 1) reverse(s.begin(), s.end());
            ans += s;
            if(j > 0) ans += '.';
            // cout << s << endl;
            j--;
        }
        return ans;
    }
};
