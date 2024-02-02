class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        
        // string ans = "";
        // if(s[0] == '-') ans += '-';
        // for(int i = 0; i < s.length(); i++) {
            
        //     // find the value at ith index
        //     int val = s[i] - '0';
        //     // check for all the digits from 0 to 9
            
        //     if(val == 0 || val == 1 || val == 2 || val == 3 || val == 4 || val == 5 || val == 6 || val == 7 
        //             || val == 8 || val == 9){
        //                 ans += s[i];
        //                  continue;
        //             }
        //     else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (i > 0 && s[i] == '-') ) return -1;
        // }
        
        // int ans1 = stoi(ans);
        // return ans1;
        
        
        bool negative;
        int ans = 0;
        // check oth index for negative value
        if(s[0] == '-') negative = true;
        
        else if(s[0] >= '0' && s[0] <= '9') ans = s[0] - '0';
        else return -1; // because it is not a numeric number
        
        // now convert that string into integer
        
        for(int i = 1; i < s.length(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + s[i] - '0';
            }
            else return -1; // noq numeric number
        }
        
        
        // if string have a negative sign 
        if(negative) return -ans;
        return ans;
        
    }
};
