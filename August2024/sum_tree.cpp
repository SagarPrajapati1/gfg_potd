/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{   
    private:
    pair<bool, int> fastSum(Node *root){
        if(root == nullptr){
            pair<bool, int> p = make_pair(true, 0);
            return p;
            
        }
        
        if(root -> left == nullptr && root -> right == nullptr){
            pair<bool, int> p = make_pair(true, root -> data);
            return p;
        }
         
        pair<bool, int> leftsum = fastSum(root -> left);
        pair<bool, int> rightsum = fastSum(root -> right);
         
        bool left = leftsum.first;
        bool right = rightsum.first;
         
        bool value =  root -> data == leftsum.second + rightsum.second;
        
        pair<bool, int> ans;
        
        if(left && right && value){
            ans.first = true;
            ans.second = 2 * root -> data;
        }
        else ans.first = false;
        
        return ans;
    }
    public:
    bool isSumTree(Node* root)
    {
        // Your code here
        
        return fastSum(root).first;
    }
};
