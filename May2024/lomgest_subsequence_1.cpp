class Solution {
  public:
    int solve(int i, int prev, vector<int> &a){
       if(i >= a.size()){
           
           return 0;
       }
        
        // pick the element
        
        int pick = 0;
        if(prev == -1 || abs(a[i] - a[prev]) == 1) pick = 1 + solve(i+1, i, a);
        
        
        // not pick the element
        int notPick = solve(i+1, prev, a);
    
        return max(pick, notPick);
    }
  
    int longestSubseq(int n, vector<int> &a) {
        // code here
        
        int ans = solve(0, -1, a);
        return ans;
        
    }
};
