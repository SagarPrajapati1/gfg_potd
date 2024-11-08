class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        string str = s1;
        int cnt = 1;
        
        while(s1.size() < s2.size()){
            s1 += str;
            cnt++;
        }
        
        if(s1.find(s2) != -1) return cnt;
        s1 += str;
        cnt++;
        if(s1.find(s2) != -1) return cnt;
        return -1;
        
    }
};
