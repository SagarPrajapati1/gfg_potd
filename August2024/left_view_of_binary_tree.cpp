/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
void solve(Node* root, vector<int> &ans, int val) {
    if(root == NULL) return;
    
    if(val == ans.size()) ans.push_back(root -> data);
    
   
    solve(root -> left, ans, val+1);

    solve(root -> right, ans, val+1);
 
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}
