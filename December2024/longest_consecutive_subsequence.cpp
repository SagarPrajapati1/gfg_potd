class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int ans = 0;
        int cnt = 1;
        sort(arr.begin(), arr.end());
        
        for(int i  = 1; i < arr.size(); i++) {
            if(arr[i-1] + 1 == arr[i]){
                cnt++;
            }
            else if(arr[i-1] == arr[i]){
                continue;
            }
            else cnt = 1;
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};
