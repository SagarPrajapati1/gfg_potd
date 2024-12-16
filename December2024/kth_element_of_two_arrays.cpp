class Solution {
  public: 
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i = 0;
        int j = 0;
        int cnt = 0;
        
        vector<int> ans;
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) {
                ans.push_back(a[i]);
                i++;
            }
            else {
                ans.push_back(b[j]);
                j++;
            }
        }
        
        while(i < a.size()){
            ans.push_back(a[i]);
            i++;
        }
        
        while(j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }
        
        if(ans.size() < k) return -1;
        return ans[k-1];
    }
};
