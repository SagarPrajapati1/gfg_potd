class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> cnt(26);
        int count = 0;
        for(auto it : s){
          cnt[it -'a']++;
        }
        
        int c = 0;
        for(int i = 0; i < 26; i++){
            if(cnt[i] > 0){
                int val = i+1;
                int val2 = cnt[i];
                if(val % 2 == val2 % 2) c++;
            }
        }
        
        if(c & 1) return "ODD";
        return "EVEN";
        
    }
};
