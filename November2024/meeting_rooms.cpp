class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n=arr.size();
        int m =arr[0].size();
    
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mini=min(mini,arr[i][j]);
                maxi=max(maxi,arr[i][j]);
            }
        }
         vector<int> b(maxi+1,0);
         //initialize till mini-1 to 1 ;
         for(int i=0;i<mini;i++)b[i]=1;
         for(int i=0;i<n;i++){
             vector<int>temp=arr[i];
             int lo=arr[i][0];
             int up=arr[i][1];
             for(int j=lo ;j<up;j++){
                 if(b[j]==1)return false;
                 
                 b[j]=1;
             }
         }
        return true;
    }
};
