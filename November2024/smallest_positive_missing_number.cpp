class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        sort(begin(arr), end(arr));
        int i = 0;
        int temp = 1;
        int n = arr.size();
        while(i < n){
            if(arr[i] > temp) return temp;
            
            else if(arr[i] == temp) temp++;
            
            i++;
        }
        return temp;
    }
};
