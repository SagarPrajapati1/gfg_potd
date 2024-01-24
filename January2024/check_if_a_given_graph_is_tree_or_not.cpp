class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        // using bfs
        // creating adjacency list
        vector<vector<int>> adjList(n);
        for(auto it: adj) {
            int u = it[0];
            int v = it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // create a visited array of visited nodes of graph
        vector<int> vis(n,0);
        // make first node as visited
        vis[0] = 1;
        // create a queue to traverse level order
        queue<pair<int, int>> q;
        q.push({0, -1});
        
        // run a loop untill all the nodes are visited
        while(!q.empty()) {
            
            // take the fisrt node and it's parent
            int node = q.front().first;
            int parent = q.front().second;
            
            // pop the first node and parent
            q.pop();
            
            // check all the connected nodes to that node if it is visited or not
            for(auto it : adjList[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if(it != parent) return 0;
            }
        }
        
        // check if all nodes are visited or not 
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) return 0;
        }
        return 1;
    }
};
