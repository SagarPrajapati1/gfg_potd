class Solution{
public:	

    bool solve(int arr[], int n = 26){
        bool f = true;
        int val = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                continue;
            }
            if(val == 0) val = arr[i];
            if(val != arr[i]) return false;
        }
        return true;
    }
	bool sameFreq(string s)
	{
	    // code here
	    int n = s.length();
	    int arr[26] = {0};
	    for(int i = 0; i < n; i++){
	        arr[s[i] - 'a']++;
	    }
	    
	    if(solve(arr)) return true;
	    
	    for(int i = 0; i < 26; i++){
	        if(arr[i] == 0){
	            continue;
	        }
	        arr[i]--;
	        bool flag = solve(arr);
	        arr[i]++;
	        if(flag){
	            return true;
	        }
	    }
	    return false;
	}
};
