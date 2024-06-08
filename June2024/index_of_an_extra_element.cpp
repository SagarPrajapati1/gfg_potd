class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr1[i]]++;
            mp[arr2[i]]--;
        }
        int sol;
        for(auto it:mp)
        {
            if(it.second==1) sol=it.first;
        }
        auto it=find(arr1,arr1+n,sol);
        int index=0;
        if (it!=arr1+n)  
        { 
            index=it-arr1; 
        } 
        return index;
    }
};
