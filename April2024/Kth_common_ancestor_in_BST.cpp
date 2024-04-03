//Back-end complete function Template for C++

class Solution
{
    public:
    Node* LCA(Node *root, int x, int y)
    {
        // base case
        if(root==NULL)
            return NULL;
        
        //If both x and y are smaller than data at current node, we call 
        //the function recursively for finding LCA in the left subtree. 
        if(x<root->data and y<root->data)
        {
            return LCA(root->left,x,y);
        }
        //If both x and y are greater than data at current node, we call 
        //the function recursively for finding LCA in the right subtree. 
        if(x>root->data and y > root->data)
        {
            return LCA(root->right,x,y);
        }
        
        //returning the lowest common ancestor.
        return root;
    }
    
    void pathToNode(Node *root, Node *node, vector<int>&path)
    {
        path.push_back(root->data);
        if(root->data==node->data)
            return;
        else if(node->data>root->data)
            pathToNode(root->right,node,path);
        else
            pathToNode(root->left,node,path);
    }
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        Node *lca=LCA(root,x,y);
        vector<int>path;
        pathToNode(root,lca,path);
        reverse(path.begin(),path.end());
        if(path.size()<k)
            return -1;
        return path[k-1];
    }
};


class Solution
{
    public:
    int val;
    int solve(Node* root, int x, int y) {
        
        // left side
        if(x <= root -> data && y <= root -> data){
            solve(root-> left, x, y);
        }
        // right side
        else if(x >= root -> data && y >= root -> data){
            solve(root -> right, x, y);
        }
        // both side
        else if(x <= root -> data && y >= root -> data)
            return root -> data;
    }
    
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        if(root == nullptr) return -1;
        
        vector<int> ans;
        while(root){
            ans.push_back(root -> data);
            // left side
            if(x < root -> data && y < root -> data){
                root = root -> left;
            }
            // right side
            else if(x > root -> data && y > root -> data){
                root = root -> right;
            }
            else break;
        }
        
        if(ans.size() < k) return -1;
        return ans[ans.size() - k];
    
    }
};
