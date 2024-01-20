class Solution
{
    public:
    int distributer(Node * root , int& ans){
        if (root == 0) return 0;
        int r = distributer(root-> right , ans);
        int l = distributer(root-> left , ans);
        ans += abs(l) + abs(r);
        return root->key + l + r - 1; 
    }
    int distributeCandy(Node* root)
    {
        int ans =0;
        distributer(root , ans);
        return ans;    

    }
};
