class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        
        // long long n = s.length();
        
        // // 1st case if last digit is odd
        // if(s[s.length() - 1] % 2 != 0) return -1;
        
        // long long num = 0;
        // if(n == 2 || n == 1){
        //     int num = stoi(s);
        //     if(num % 8 == 0) return 1;
        //     else return -1;
        // }
        
        // string str = s.substr(s.length() - 3);
        
        // num = stoi(str);
        
        // if(num % 8 == 0) return 1;
        
        // return -1;
        
        
        int num = stoi(s.substr(max((int)s.length() - 3, 0)));
        
        return num % 8 ? -1 : 1;
        
    }
};
