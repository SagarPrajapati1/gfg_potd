class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int, int> prefix;
	    
	    prefix[0] = -1;
	    
	    int res = 0, sum = 0;
	    
	    for(int i = 0; i < n; i++) {
	        sum += arr[i];
	        int rem = sum % k;
	        if(rem < 0) rem += k;
	        
	        if(prefix.find(rem) == prefix.end()) prefix[rem] = i;
	        else res = max(res, i - prefix[rem]);
	    }
	    return res;
	    
	}
};
