class Solution {
  public:
    int edge=0;
    int vertices=0;
    void dfs(int i, vector<vector<int>>&adj, vector<bool> &isVisited)
    {
        isVisited[i]=true;
        edge+=adj[i].size();
        
        for(auto node:adj[i])
        {
            if(!isVisited[node])
            {
                vertices++;
                dfs(node, adj, isVisited);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        
        vector<bool> isVisited(v+1, 0);
        int full=0;
        
        vector<vector<int>> adj(v+1);
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        for(int i=1;i<=v;i++)
        {
            if(!isVisited[i])
            {
                edge = 0;
                vertices=1;
                dfs(i, adj, isVisited);
                if((vertices*(vertices-1))/2 == edge/2)
                    full++;
            }
        }
        return full;       
    }
};
