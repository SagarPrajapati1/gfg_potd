/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    Node* solve(Node* root, Node* temp){
        if(root == nullptr) return temp;
        
        Node* l = root->left;
        Node* r = root->right;
        
        root -> left = root -> right = nullptr;
        solve(l, temp)->right = root;
        return solve(r, root);
    }

    Node *flattenBST(Node *root)
    {
        // code here
        Node* temp = new Node(0);
        solve(root, temp);
        return temp->right;
    }
};
