class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int X) {
        // your code here
	    int s = 0;
	    int N = mat.size();
	    int M = mat[0].size();
	    int e =  M - 1;
	    while(s < N  && e >= 0) {
	        int element = mat[s][e];
	        
	        if(element == X) {
	            return 1;
	        }
	        else if(element < X) {
	            s++;
	        }
	        else e--;
	    }
	    return 0;
    }
};
