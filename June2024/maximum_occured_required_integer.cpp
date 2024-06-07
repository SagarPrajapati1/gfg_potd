class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        int diffArr[maxx+1] = {0};
        for(int i = 0; i<n; i++){
            diffArr[l[i]]++;
            diffArr[r[i]+1]--;
        }
        
        
        int ans = 0;
        int maxi = 0;
        
        
        
        for(int i = 1; i<maxx; i++){
            diffArr[i] += diffArr[i-1];
        }
        
        for(int i = 1; i<maxx; i++){
            if(maxi < diffArr[i]){
                maxi = diffArr[i];
                ans = i;
            }
        }
        
        return ans;
        
    }
};
