class Solution {
  public:
     void func(vector<int>&arr,int n,set<vector<int>>&st,vector<int>&curr,int picked)
    {
        if(picked==((1<<n)-1)) 
        {
           st.insert(curr);
            return;
        }
        for (int i=0;i<n;i++)
        {
            if (((1<<i)&picked)==0)
            {
                curr.push_back(arr[i]);
                func(arr,n,st,curr,picked|(1<<i));
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) 
    {
        set<vector<int>>st;
       vector<vector<int>>ans;
       int picked=0;
       vector<int>curr;
       func(arr,n,st,curr,picked);
       for (auto it: st) {
          
           ans.push_back(it);}
       return ans;
    }
};
