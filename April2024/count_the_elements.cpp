class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        // Your code goes here;
        // vector<int> ans;
        // for(int k = 0; k < q; k++){
        //     int cnt = 0;
        //     int val = a[query[k]];
        //     for(int i = 0; i < n; i++){
        //         if(b[i] <= val) cnt++;
        //     }
        //     ans.push_back(cnt);
        // }
        // return ans;
        
        int mx=-1;
        for(int i=0; i<n; i++) mx = max(mx,b[i]);
        
        vector<int> countB(mx+1, 0);
        for(int i = 0; i < n; i++){
            countB[b[i]]++;
        }
        
        for(int i=1; i <= mx; i++) {
            countB[i] += countB[i-1];
        }
        
        vector<int> ans;
        for(int i = 0; i < q; i++) {
            if(a[query[i]] > mx) ans.push_back(n);
            else ans.push_back(countB[a[query[i]]]);
        }
        return ans;
    }
};
