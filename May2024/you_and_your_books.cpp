class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        int left=0,right=0;
        long long maxi=0; 
        long long sum=0; 
        while(right<n){
           if(arr[right]<=k){
                sum+=arr[right];
                maxi=max(maxi,sum);
            }
            else{
                left=right;
                sum=0;
            }
                right++;
        }
        return maxi;
    }
};
