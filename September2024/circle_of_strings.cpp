class Solution {
  public:
        void DFS(char u,unordered_map<char,vector<char>>& adj,unordered_map<int,bool>& visited){
        visited[u] = true;
        
        for(auto v: adj[u]){
            if(visited[v] == false){
                DFS(v,adj,visited);
            }
        }
    }
    int isCircle(vector<string> &arr) {
        unordered_map<char,vector<char>> adj;
        
        for(int i=0;i<arr.size();i++){
            int u = arr[i][0];
            int v = arr[i][arr[i].size()-1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count = 0;
        unordered_map<int,bool> visited;
        
        for(int i=0;i<arr.size();i++){
            if(visited[arr[i][0]] == false){
                DFS(arr[i][0],adj,visited);
                count++;
            }
        }
        
        int odd = 0;
        for(auto i: adj){
            if(adj[i.first].size()&1){
                odd++;
            }
        }
        
        if(count > 1 || odd != 0){
            return 0;
        }
        return 1;
    }
};
