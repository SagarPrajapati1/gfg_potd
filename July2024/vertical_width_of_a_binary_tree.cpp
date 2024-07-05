class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        set<int> sz;
        if (root == nullptr) return 0;
        while(!q.empty()) {
            Node* frontNode = q.front().first;
            int hd = q.front().second;
            
            sz.insert(hd);
            
            q.pop();
            
            
            if (frontNode -> left) {
                q.push({ frontNode -> left, hd-1 });
            }
            
            if (frontNode -> right) {
                q.push({ frontNode -> right, hd+1 });
            }
        }
        
        return sz.size();
    }
};




class Solution {
  public:
    void preorder(Node* root, int x, int& mn, int &mx){
        if(!root) return;
        mn=min(mn,x);  // store min x-coord
        mx=max(mx,x);  // store max x-coord
        preorder(root->left, x-1, mn, mx);  // call for root->left with (x-1) coord
        preorder(root->right, x+1, mn, mx); // call for root->left with (x+1) coord
    }
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        if(!root) return 0;  // edge case
        int mn=INT_MAX, mx=INT_MIN; //mn stores minimum x-coordinate, mx stores maximum x-coordinate of node
        preorder(root, 0, mn, mx);  //call preorder with root's x-coordinate equal to 0
        return mx-mn+1; //return no of columns
    }
};






 void fun(Node* root,int i,unordered_map<int,int> &um){
        if(root==NULL)    
            return;
        um[i]=root->data;
        fun(root->left,i-1,um);
        fun(root->right,i+1,um);
        return;
    }
    
    int verticalWidth(Node* root) {
        // code here
        unordered_map<int,int> um;
        fun(root,0,um);
        return(um.size());
    }
