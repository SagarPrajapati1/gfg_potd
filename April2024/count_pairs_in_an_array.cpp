#include <ext/pb_ds/assoc_container.hpp> // Including necessary headers
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; // Using the namespace for pb_ds

typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; // Defining a data structure pbds using GNU pb_ds
class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        for (int i = 0; i < n; i++) {
            arr[i] *= i;
        }

        pbds st; // Create an instance of pbds tree
        int ans = 0; // Initialize the answer variable
        for (int i = 0; i < n; i++) {
            // Add the number of elements greater than or equal to arr[i] in the pbds tree to the answer
            ans += st.order_of_key(arr[i]);
            // Insert arr[i] into the pbds tree
            st.insert(arr[i]);
        }
        return ans; // Return the final answer
    }
};

class Solution{
    public:
    int countPairs(int arr[] , int &n ) 
    {
           int count=0,k=0;
       for(int i=0;i<n;i++){
           k=i;
           for(int j=k;j<n; j++){
               if((i*arr[i])>(j*arr[j]))
                   count++;
           }
       }
       return count;
    }
};

class Solution{
    public:
    // Return count of pair in given array 
    // such that  i*arr[i] > j*arr[j] 
    int merge(int arr[], int temp[], int left, 
                           int mid, int right) 
    { 
        int inv_count = 0; 
      
        int i = left; /* index for left subarray*/
        int j = mid;  /* index for right subarray*/
        int k = left; /* ndex for resultant subarray*/
        while ((i <= mid - 1) && (j <= right)) 
        { 
            if (arr[i] <= arr[j]) 
                temp[k++] = arr[i++]; 
            else
            { 
                temp[k++] = arr[j++]; 
      
                inv_count = inv_count + (mid - i); 
            } 
        } 
      
        /* Copy the remaining elements of left 
         subarray (if there are any) to temp*/
        while (i <= mid - 1) 
            temp[k++] = arr[i++]; 
      
        /* Copy the remaining elements of right 
         subarray (if there are any) to temp*/
        while (j <= right) 
            temp[k++] = arr[j++]; 
      
        /* Copy back the merged elements to original 
          array*/
        for (i=left; i <= right; i++) 
            arr[i] = temp[i]; 
      
        return inv_count; 
    } 
      
    /* An auxiliary recursive function that sorts 
       the input array and returns the number of 
       inversions in the array. */
    int _mergeSort(int arr[], int temp[], int left, 
                                          int right) 
    { 
        int mid, inv_count = 0; 
        if (right > left) 
        { 
            /* Divide the array into two parts and call 
              _mergeSortAndCountInv() for each of 
              the parts */
            mid = (right + left)/2; 
      
            /* Inversion count will be sum of inversions in 
               left-part, right-part and number of inversions 
               in merging */
            inv_count  = _mergeSort(arr, temp, left, mid); 
            inv_count += _mergeSort(arr, temp, mid+1, right); 
      
            /*Merge the two parts*/
            inv_count += merge(arr, temp, left, mid+1, right); 
        } 
      
        return inv_count; 
    } 
      
    /* This function sorts the input array and 
       returns the number of inversions in the 
       array */
    int countPairs(int arr[], int n) 
    { 
        // Modify the array so that problem reduces to 
        // count inversion problem. 
        for (int i=0; i<n; i++) 
            arr[i] = i*arr[i]; 
      
        // Count inversions using same logic as 
        // below post 
        // https://www.geeksforgeeks.org/counting-inversions/ 
        int temp[n]; 
        return _mergeSort(arr, temp, 0, n - 1); 
    } 
};
