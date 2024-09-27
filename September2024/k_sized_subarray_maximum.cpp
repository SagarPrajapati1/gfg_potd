
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        list<int> li;
        
        // {
        // int i = 0;
        // int j = 0;
        // vector<int> ans;
        // int n = arr.size();
        // int maxi = INT_MIN;
        
        // while(j < k){
        //     li.push_back(arr[j]);
        //     maxi = max(maxi, arr[j]);
        //     j++;
        // }
        
        // i = 1;
        
        // ans.push_back(maxi);
        // li.pop_front();
        // li.push_back(arr[j]);
        
        // while(j < arr.size()) {
            
        //     if(j-i+1 == k) {
        //         maxi = *max_element(li.begin(), li.end());
        //         i++;
        //         li.pop_front();
        //         j++;
        //         li.push_back(arr[j]);
        //         ans.push_back(maxi);
        //     }
        // }
        // return ans;
            
        // } // TLE
        
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++) {
            if(!li.empty() && li.front() == i-k) {
                li.pop_front();
            }
            
            while(!li.empty() && arr[i] > arr[li.back()]){
                li.pop_back();
            }
            
            li.push_back(i);
            
            if(i >= k-1) ans.push_back(arr[li.front()]);
        }
        return ans;
        
        
        
    }
    
};
