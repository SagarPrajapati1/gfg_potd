class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], 
            int tin[], int low[], vector<vector<int>> &bridges) {
            
            
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto it: adj[node]){
            if(it == parent) continue;
            
            if(vis[it] == 0){
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                
                if(low[it] > tin[node]){
                    int mini = min(it, node);
                    int maxi = max(it, node);
                    bridges.push_back({mini, maxi});
                }
                
            }
            
            else {
                
                low[node] = min(low[it], low[node]);
                
            }
        }
    }
    
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<int> vis(v, 0);;
	    int tin[v];
	    int low[v];
	    
	    vector<vector<int>> bridges;
	    
	    dfs(0, -1, vis, adj, tin, low, bridges);
	    sort(bridges.begin(), bridges.end());
	    return bridges;
	    
	    
	}
};
