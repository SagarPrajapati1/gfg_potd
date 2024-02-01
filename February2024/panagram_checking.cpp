class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        int letters[26] = {};
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                letters[s[i] - 'a']++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z') {
                letters[s[i] - 'A']++;
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(letters[i] == 0) return 0;
        }
        return 1;
    }

};
