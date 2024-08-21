class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> path(N, -1);
        vector<bool> vis(N, 0);
        
        vector<int> adj[N];
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        path[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                    path[it] = path[node] + 1;
                }
            }
        }
        
        return path;
    }
};
