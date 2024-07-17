/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        queue<Node*> q;
        Node* root;
        
        int n=parent.size();
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                root=new Node(i);
                q.push(root);
                break;
            }
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[parent[i]].push_back(i);
        }
        
        
        while(!q.empty()){
            auto node=q.front(); q.pop();
            int cnt=0,rc=-1,lc=-1;
            if(mp.find(node->data)!=mp.end()){
                
                    lc=mp[node->data][0];
                    if(mp[node->data].size()>1) rc=mp[node->data][1];
                }
            if(lc!=-1) { node->left=new Node(lc); q.push(node->left); }
            if(rc!=-1) { node->right=new Node(rc); q.push(node->right); }
        }
        return root;
    }
};
