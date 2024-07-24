class Solution
{
    public:
    
    bool isValidBST(Node* root, int minVal, int maxVal) {
        
        if(root == nullptr) return true;
        if(root -> data <= minVal || root -> data >= maxVal) return false;
        
        return isValidBST(root -> left, minVal, root->data) 
        && isValidBST(root -> right, root->data, maxVal);
    }
    
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return isValidBST(root, INT_MIN, INT_MAX);
    }
};
