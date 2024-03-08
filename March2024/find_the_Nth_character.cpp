class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
            string str = s;
        while(r--){
            string str1 = str;
            str = "";
            for(int i = 0; i < s.length(); i++){
                if(str1[i] == '1'){
                    str += "10";
                }
                else if(str1[i] == '0') {
                    str += "01";
                }
            }
        }
        
        return str[n];
    }
};
