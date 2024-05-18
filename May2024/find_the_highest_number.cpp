class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        // int maxi = INT_MIN;
        // for(int i  = 0; i < a.size(); i++){
        //     maxi = max(maxi, a[i]);
        // }
        // return maxi;
        
        int s = 0;
        int e = a.size()-1;
        
        int mid;
    
        while(s < e){
           
            mid = s + (e-s)/2;
     
            if(a[mid] > a[mid+1]) e = mid;
            else  s = mid + 1;
             
        }
        return a[s];
    }
};
