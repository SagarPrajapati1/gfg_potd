class Solution {
  public:
    int maxLength(string& str) {
        int open = 0, close = 0, max_len = 0;
    
   
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                open++;
            } else if (str[i] == ')') {
                close++;
            }
    
            if (open == close) {
                max_len = max(max_len, 2 * close); 
            } else if (close > open) {
                open = close = 0;  
            }
        }

  
        open = close = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] == '(') {
                open++;
            } else if (str[i] == ')') {
                close++;
            }
    
            if (open == close) {
                max_len = max(max_len, 2 * open); 
            } else if (open > close) {
                open = close = 0; 
            }
        }
    
        return max_len;
    }
};
