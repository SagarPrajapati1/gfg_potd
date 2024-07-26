class Solution {
  public:

    bool kPangram(string str, int k) {
        int n = str.size(), space = 0;
        if(n < 26)  return false;
        vector<bool> arr(26, false);
        for(int i=0; i<n; i++) {
            if(str[i] == ' ')   space++;
            else arr[str[i] - 'a'] = true;
        }
        int count = 0;
        for(int i=0; i<26; i++)
            if(arr[i])
                count++;
        int nonSpace = n - space;
        int avail = nonSpace - count;
        
        return (26 - count) <= min(avail, k);
    }
};


class Solution {
  public:

    bool kPangram(string s, int k) {
        // code here\
        
        string str = "";

        map<char, int> mp;
        
        for (auto it : s){
            if(it != ' '){
                mp[it]++;
                str += it;
            }
        }
        
        if(str.length() < 26) return false;
        
        if(mp.size() == 26) return true;
        
        return (26 - mp.size()) <= k;
    }
};
