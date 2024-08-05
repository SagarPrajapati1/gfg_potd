class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        map<int, int> nodes;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        if(root == nullptr) return{};    
        
        while(!q.empty()){
            Node* frontNode = q.front().first;
            int hd = q.front().second;
            q.pop();
            nodes[hd] = frontNode -> data;
            
            if(frontNode->left) q.push({frontNode->left, hd-1});
            if(frontNode->right) q.push({frontNode->right, hd+1});
            
        }
        vector<int> ans;
        for(auto it: nodes){
            ans.push_back(it.second);
        }
        return ans;
    }
};
