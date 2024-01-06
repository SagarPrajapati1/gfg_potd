class Solution {
    void solve(int num, int &total) {
        vector<int> factor;
	    for(unsigned int i = 2; i*i <= num; ++i) {
	        if(num % i == 0) {
	            while(num % i == 0){
	                factor.push_back(i);
	                num /= i;
	            }
	        }
	    }
	    
	    if(num > 1) factor.push_back(num);
	    
	    int n = factor.size();
	    total+= n;
    }
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans = 0;
	    for(int i = a; i <= b; i++) {
	        solve(i, ans);
	    }
	    
	    return ans;
	}
};
