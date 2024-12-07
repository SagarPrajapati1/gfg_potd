class Solution{
  private:
    int inversion(vector<int>& arr, int s,int mid, int e, int &ans){
        
        if(s >= e) return 0;
        
        int i = s, j = e, k = mid + 1;
        
        
        
        // ans+= inversion(arr, s, mid, e, ans);
        // ans+= inversion(arr, s, mid + 1, e, ans);
        
        int b[e];
        int m = s;
        
        while(i <= mid && k <= j) {
            if(arr[i] <= arr[k]) {
                b[m++] = arr[i++];
            }
            
            else{
                b[m++] = arr[k++];
                ans = ans + (mid - i + 1);
            }
        }
        
        while(i <= mid) {
            b[m++] = arr[i++];
        }
        
        while(k <= e) {
            b[m++] = arr[k++];
        }
        
        for(int i = s; i <= e; i++) {
            arr[i] = b[i];
        }
        
        
    
    }
  
    void mergeSort(vector<int> & arr, int s, int e, int &ans) {
        if(s >= e) return;
        
        if(s < e)
       { int mid = s + (e-s)/2;
        
        // left part
        mergeSort(arr, s, mid, ans);
        
        // right part
        mergeSort(arr, mid + 1 , e, ans);
        
        // merge
        
        inversion(arr, s, mid, e, ans);
       }
    }
  
  
  
  public:
    int inversionCount(vector<int> &arr) {
        int N = arr.size();
        
            int ans = 0;
            mergeSort(arr, 0, N-1, ans);
        
        return ans;
        
    }

};
