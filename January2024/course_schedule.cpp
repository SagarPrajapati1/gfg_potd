class Solution
{
  public:

    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        // create a graph
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        for(int i = 0; i < m; i++) {
            int u = pre[i][0];
            int v = pre[i][1];
            
            adj[v].push_back(u);
            deg[u]++;
        }
        
        
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(!deg[i]) q.push(i);
        }
        
        vector<bool> vis(n, false);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            vis[node] = true;
            ans.push_back(node);
            
            for(auto it: adj[node]){
                deg[it]--;
                if(!deg[it]) q.push(it);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) return {};
        }
        return ans;
        
    }
};
