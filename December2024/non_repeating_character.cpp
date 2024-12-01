  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &S) {
        unordered_map<char, int> vis;
        for(auto i : S){
            vis[i]++;
        }
        
        for(int i = 0; i < S.size(); i++){
            if(vis[S[i]] == 1) return S[i];
        }
        return '$';
    }
};
