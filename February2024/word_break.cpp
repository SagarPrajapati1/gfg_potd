
// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        unordered_set<string> hs(dictionary.begin(), dictionary.end());
        
        int m = s.length();
        
        vector<bool> dp(m+1, 0);
        dp[0] = 1;
        
         for (int i = 1; i <= m; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && hs.find(s.substr(j, i - j)) != hs.end()) { // Use unordered_set's find for O(1) lookup
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[m];
        
    }
};
