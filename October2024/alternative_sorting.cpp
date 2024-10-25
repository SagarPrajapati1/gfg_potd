class Solution {

  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
    
        sort(arr.begin(),arr.end());
        
        
        int i=0;
        int j=arr.size()-1;
        
        
        vector<int>ans;
            
        
        while(i<j){
            
            ans.push_back(arr[j]);
           
            
            ans.push_back(arr[i]);
            
            
            i++;
            j--;
        }
        
        if(arr.size()%2!=0)
            ans.push_back(arr[i]);
            
        return ans;
    }
};
