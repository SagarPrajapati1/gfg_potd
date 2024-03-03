class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    
	    sort(arr.begin(), arr.end(), [](string &left, string& right){
	        return left + right > right + left;
	    });
	    
	    string res = "";
	    for(auto it: arr) res += it;
	    return res;
	    
	}
};
