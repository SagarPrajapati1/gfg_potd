/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool solve(int val, int target, Node* root) {
        if(!root) return false;
        val += root -> data;
        if(!root -> left && !root -> right) return val == target;
        

        return solve(val, target, root -> left) || solve(val, target, root -> right);
    }
    
    bool hasPathSum(Node *root, int target) {
        // Your code here
        
        return solve(0, target, root);
    }
};
