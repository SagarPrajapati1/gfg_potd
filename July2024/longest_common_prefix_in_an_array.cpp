class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        
        int minLength = INT_MAX;
        string str = "";
        
        for(auto it : arr){
            if(minLength > it.length()){
                minLength = it.length();
                str = it;
            }
        }
        
        // cout << str << endl;
        
        string ans = "";
        while(minLength > 0)
        {
            
            for(int i = 0; i < n; i++){
                
                string temp = "";
                string s = arr[i];
                temp = s.substr(0, minLength);
                
                // cout << str << " ";
                if(str != temp) {
                    str = str.substr(0, minLength-1); // missed this one add after thinking about wrong answer
                    break;
                }
                
                // else ans = str;
                if(i == n-1 && str == temp) return str;
            }
            // cout << endl;
            
            minLength--;
        }
        
        return "-1";
    }
};
