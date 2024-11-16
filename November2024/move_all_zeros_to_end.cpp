class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int e = 0;
        int n = arr.size();
	    for(int s = 0; s < n; s++) {
	        if(arr[s] != 0){
	            swap(arr[s], arr[e]);
	            e++;
	        }
	    }
    }
};
