class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int maxi = 0;
        sort(citations.begin(), citations.end());
        for(int i=n-1; i>=0; i--){
            if(n-i<=citations[i])
            maxi=max(maxi, n-i);
        }
        return maxi;
    }
};
