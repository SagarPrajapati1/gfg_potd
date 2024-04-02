class Solution
{
    public:
    void inorder(Node*root, vector<int>& in){
        if(root == nullptr) return;
        
        inorder(root -> left, in);
        in.push_back(root -> data);
        inorder(root -> right, in);
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        vector<int> diff;
        inorder(root, diff);
        int mini = INT_MAX;
        
        for(int i = 0; i < diff.size() - 1; i++) {
            mini = min(mini, abs(diff[i] - diff[i+1]));
        }
        return mini;
    }
};
