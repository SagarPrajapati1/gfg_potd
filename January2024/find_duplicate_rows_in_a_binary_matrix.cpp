class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &m, int r, int c) 
    { 
        // Your code here
        vector<int>ans;
        set<vector<int>>us;
        for(int i = 0; i<r; i++)
        {
            vector<int>v;
            for(int j = 0; j<c; j++)
            {
                v.push_back(m[i][j]);
            }
            if(us.find(v) == us.end())
                us.insert(v);
            else if(us.find(v) != us.end())
                ans.push_back(i);
        }
        return ans;
    } 
};
