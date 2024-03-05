class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        
        // O(N^2) Solution
        // int maxi = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     for(int j = i+1; j < n; j++) {
        //         if(a[i] <= a[j]) maxi = max(maxi, j-i);
        //     }
        // }
        // return maxi;
        
        // O(N) & O(N) Solution
        
        int left[n];
        int right[n];
        
        left[0] = a[0];
        right[n-1] = a[n-1];
        
        int j = n-2;
        
        for(int i = 1; i < n; i++){
            left[i] = min(left[i-1], a[i]);
            right[j] = max(right[j+1], a[j]);
            j--;
        }
        
        int i = 0;
        j = 0;
        int res = -1;
        while(i < n && j < n){
            if(left[i] <= right[j]){
                res = max(res, j-i);
                j = j+1;
            }
            else i = i+1;
        }
        return res;
        
        
        // O(N) && O(1)
        
        // int i = 0;
        // int j = n-1;
        // int ans = 0;
        // while(i <= j){
        //     if(a[i] <= a[j]){
                
        //         ans = max(ans, j-i);
        //         i++;
        //         j = n-1;
        //     }
        //     else {
        //         j--;
        //     }
        // }
        // return ans;
    }
};
