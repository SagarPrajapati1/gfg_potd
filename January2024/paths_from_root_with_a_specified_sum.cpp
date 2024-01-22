class Solution
{
    public:
    
    void solve(Node* root, vector<vector<int>> &ans, vector<int> &temp, int target, int sum) {
        
        // base case
        if(root == nullptr) return;
        
        // insert the path value
        temp.push_back(root -> key);
        
        // add value into the sum
        sum += root -> key;
        
        // it target is acheived
        if(sum == target) ans.push_back(temp);
        
        // call recursively for left and right subtree
        solve(root -> left, ans, temp, target, sum);
        solve(root -> right, ans, temp, target, sum);
        
        // backtrack
        temp.pop_back();
        
    }
    
    vector<vector<int>> printPaths(Node *root, int target)
    {
        //code here
        vector<vector<int>> ans;
        int sum = 0;
        
        vector<int> temp;
        
        solve(root, ans, temp, target, sum);
        if(ans.size() != 0) return ans;
        else ans.push_back({-1});
        return ans;
    }
};
