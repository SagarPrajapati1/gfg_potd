class Solution {
  public:
    // int findMin(vector<int>& arr) {
    //     // complete the function here
    //     int m = INT_MAX;
    //     for(int i = 0; i < arr.size(); i++) {
    //         m = min(m, arr[i]);
    //     }
    //     return m;
    // }
    
    
    int findMin(vector<int>& arr) {
        // complete the function here
        int n=arr.size();
        int lo=0, hi=n-1;
        int ans=INT_MAX;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            
            if(arr[lo]<=arr[hi]){
                ans=min(ans, arr[lo]);
                break;
            }
            
            if(arr[lo]<=arr[mid]){
                ans=min(ans, arr[lo]);
                lo=mid+1;
            }else{
                ans=min(ans, arr[mid]);
                hi=mid-1;
            }
        }
        return ans;
    }
};
