class Solution {
  public:
    int minJumps(vector<int>& arr) {
         // if the size of the array is 1 then return 0 
        // becoz no jump required 
        int n = arr.size();
        if(n == 1) return 0;
        
        // if firdt value is zero then we can't move further so return -1
        if(arr[0] == 0) return -1;
        
        // how many steps we can take 
        int step = arr[0];
        
        // number of jumps 
        int jump = 1;
        
        // max Reach
        int mr = arr[0];
        
        for(int i =1; i < n; ++i){
            
            // i is at last index then just return jump
            if(i == n - 1) return jump;
            
            // find max Reach
            mr = max(mr, i + arr[i]);
            step--;
            if(step == 0) {
               
                ++jump;
                
                if(mr <= i) return -1;
                
                step = mr - i;
            }
            
            
            
        }
    }
};
