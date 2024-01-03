class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        
        int zeroCnt = -1;
        int oneCnt = -1;
        int twoCnt = -1;
        
        int ans = INT_MAX;
        
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '0') zeroCnt = i;
            else if(S[i] == '1') oneCnt = i;
            else if(S[i] == '2') twoCnt = i;
            
            if(zeroCnt >= 0 && oneCnt >= 0 && twoCnt >=- 0) {
                int minInd = min(min(zeroCnt, oneCnt), twoCnt);
                int maxInd = max(max(zeroCnt, oneCnt), twoCnt);
                ans = min(ans, maxInd - minInd + 1);
            }
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
