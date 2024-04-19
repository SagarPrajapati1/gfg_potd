class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    vector<int> ans;
	    
	   set<int> st;
	    
	    for(int i = 0; i < m; i++){
	        st.insert(b[i]);
	    }
	    
	    for(int i = 0; i < n; i++){
	        if(st.find(a[i]) == st.end()){
	            ans.push_back(a[i]);    
	        }
	    }
	    return ans;
	} 
};
