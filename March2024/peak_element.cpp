class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
    // iterative solution
    //   int i = 0;
    //     for(i = 1; i < n; i++){
    //         if(arr[i] <= arr[i-1]) return i-1;
    //     }
    //     if(i == n){
    //         return i-1;
    //     } 
    //     return -1;
    

        if(n == 1) return 0;        
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2]) return n-1;
        
        int s = 1;
        int e = n-2;
        
        
        while(s <= e){
            int mid = (s+e)/2;
            
            if(arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]) return mid;
            
            else if(arr[mid] >= arr[mid - 1]) s = mid + 1; // increasing slope
            else e = mid; // decreasing slope
            
            // for multiple peaks
            // else s = mid + 1
        }
        return -1;
       
        
    }
};
