/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
  public:
    bool solve(struct Node* root, int target, vector<int>& ans) {
        if(root == nullptr) return false;
        
        if(root -> data == target) return true;
        
        bool left = solve(root -> left , target, ans);
        bool right = solve(root -> right, target, ans);
        
        if(left || right) {
            ans.push_back(root -> data);
            return true;
        }
    }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> ans;
        
        solve(root, target, ans);
        return ans;
    }
};
