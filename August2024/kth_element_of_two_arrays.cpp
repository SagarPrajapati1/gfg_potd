class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {   
        
        int arr[m+n];
        int i = 0;
        int j = 0;
        int l = 0;
      
          while(i < n && j < m){
              
                if(arr1[i] < arr2[j]){
                    arr[l++] = arr1[i];
                    i++;
                }
                else{
                    arr[l++] = arr2[j];
                    j++;
                }
            }
        
        while(i < n) {
            arr[l++] = arr1[i];
            i++;
        }
        
        while(j < m) {
            arr[l++] = arr2[j];
            j++;
        }
        
        return arr[k-1];
    }
};


class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        // merge two sorted array
        
        for(auto it: arr2) arr1.push_back(it);
        sort(arr1.begin(), arr1.end());
        
        return arr1[k-1];
    }
};
