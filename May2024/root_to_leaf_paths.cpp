/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<vector<int>> &ans, vector<int> & temp){
        if(root-> left == nullptr && root -> right == nullptr){
            temp.push_back(root -> data);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
      
        temp.push_back(root -> data);
  
        if(root -> left) solve(root -> left, ans, temp); 
      
        if(root -> right) solve(root -> right, ans, temp);
        temp.pop_back();
        
        
     
  }
    vector<vector<int>> Paths(Node* root) {
        
        if(root == nullptr) return{{}};
        // code here
        vector<vector<int> > ans;
        vector<int> temp;
        
        solve(root, ans, temp);
        return ans;
    }
};
