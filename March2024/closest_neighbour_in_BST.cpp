class Solution {
  public:
    int ans = -1;
    void solve(Node* root, int n){
        
        if(root == nullptr) return;
        if(root -> key <= n) {
            ans = root -> key;
            solve(root -> right, n);
        }
        if(root -> key > n){
            solve(root -> left, n);
        }
    }
    int findMaxForN(Node* root, int n) {
        // code here
        // solve(root, n);
        // return ans;
        
        while(root){
            if(root -> key <= n){
                ans = root -> key;
                root = root -> right;
            }
            else if(root -> key > n){
                root = root -> left;
            }
        }
        return ans;
    }
};
