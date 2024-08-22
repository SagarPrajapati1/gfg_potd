class Solution {
  public:
    unordered_map<char,vector<char>> adj;
  
    string findOrder(string dict[], int n, int k) {
        string ans;
        for(int i=0;i<n-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int l = min(s1.length(),s2.length());
            int j = 0;
            while(j < l){
                if(s1[j] != s2[j]){
                    adj[s1[j]].push_back(s2[j]);
                    break;
                }
                j++;
            }
        }
        
        unordered_map<char,int> indegree;
        for(auto i:adj){
            indegree[i.first] += 0;
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        
        unordered_map<char,bool> visited;
        
        while(k--){
            vector<pair<int,char>> p;
            for(auto i:indegree){
                if(visited[i.first] == false){
                    p.push_back({i.second,i.first});
                }
            }
            sort(p.begin(),p.end());
            if(p.size() > 0){
                char ch = p[0].second;
                ans.push_back(ch);
                for(auto j:adj[ch]){
                    indegree[j]--;
                }
                visited[ch] = true;
            }
        }
        return ans;
    }
};
