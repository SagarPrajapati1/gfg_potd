class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int first = -1;
	    int second = -1 ;
	    for(int i = 0; i < n; i++) {
	       if(arr[i] > first ) {

             second=first;
             first=arr[i];
	           
	       }
	       else if(second<arr[i] && arr[i]<first) {

             second= arr[i];
	           
	       }
	        
	    }
	    return second;
    }
};
