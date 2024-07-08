class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int s = 0;
        int e = arr.size() - 1;
        
        while(s <= e) {
            int mid = (s+e)/2;
            
            if(arr[mid] == key) return mid;
            
            
            if(arr[s] <= arr[mid]) {
                if(arr[s] <= key && key < arr[mid]) e = mid - 1;
                
                else s = mid + 1;
            }
            
            else {
                if(arr[mid] < key && key <= arr[e]) s = mid + 1;
                else e = mid - 1;
            }
        }
        return -1;
    }
};
