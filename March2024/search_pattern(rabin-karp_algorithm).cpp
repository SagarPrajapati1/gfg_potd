class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            // int j = 0;
            // int ind = 0;
            // vector<int> ans;
            // for(int i = 0; i < text.length(); i++){
                
            //     string str = text.substr(i, pattern.length());
            //     if(str == pattern) ans.push_back(i+1);

                
            // }
            // return ans;
            
            // using Rabin-Karp Algorithm
            int pHashCode = 0;
            int tHashCode = 0;
            int prime = 101;
            int totalChars = 26; // ('a' - 'z')
            vector<int> ans;
            
            int patternLength = pattern.length();
            int textLength = text.length();
            
            int value = 1;
            // calculate the value 
            for(int i = 0; i < patternLength - 1; i++){
                value = (value * totalChars) % prime;
            }
            
            // calculate the hash code for pattern and text one window
            for(int i = 0; i < patternLength; i++){
                pHashCode = (totalChars * pHashCode + pattern[i]) % prime;
                tHashCode = (totalChars * tHashCode + text[i]) % prime;
            }
            
            
            // slide the window
            for(int i = 0; i <= textLength - patternLength; i++){
                // check if both hash values are same
                if(pHashCode == tHashCode){
                    // now check for each character
                    int j = 0;
                    for(; j < patternLength; j++){
                        
                        // if ith character of text is not same as the pattern just break the loop
                        if(text[j+i] != pattern[j]) break;
                    }
                    
                    if(j == patternLength) ans.push_back(i+1);
                }
                // now calculate the next window hash value
                if(i < textLength - patternLength) {
                    tHashCode = (totalChars * (tHashCode - text[i]*value) + text[i+patternLength])%prime;
                    if(tHashCode < 0) tHashCode += prime;
                }
                    
            }
            return ans;
            
            
            
        }
     
};
