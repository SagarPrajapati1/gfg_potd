class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& a, string& b) {
        // Your code here
        int arr1[26] = {0};
        int arr2[26] = {0};
        
        
        if(a.length() != b.length()) return false;
        
        for(auto ch : a){
            arr1[ch-'a']++;
        }

        for(auto ch : b){
            arr2[ch-'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
};

