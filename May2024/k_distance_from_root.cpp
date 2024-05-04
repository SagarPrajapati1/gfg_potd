class Solution
{
    public:
    // function should print the nodes at k distance from root
    void solve(struct Node *root,int h,int k,vector<int>&ans){
        if(!root){
            return;
        }
        if(k == h){
            ans.push_back(root->data);
        }
        solve(root->left,h+1,k,ans);
        solve(root->right,h+1,k,ans);
    }
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      vector<int> ans;
      solve(root,0,k,ans);
      return ans;
    }
};
