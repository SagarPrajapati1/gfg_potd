/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    // void inOrder(Node* root, vector<Node*> &arr) {
    //     if(!root) return;
        
    //     inOrder(root -> left, arr);
    //     arr.push_back(root);
    //     inOrder(root -> right, arr);
    // }
    Node* r = new Node(-1);
    Node* d = r;
    
    void inOrder(Node* root) {
        if(!root -> left && !root -> right) {
            r -> next = root;
            r = root;
            return;
        }
        
        if(root -> left) inOrder(root -> left);
        r -> next = root;
        r = root;
        if(root -> right) inOrder(root -> right);
    }
    
    void populateNext(Node *root) {
        // vector<Node*> arr;
        
        // inOrder(root, arr);
        
        // for(int i = 1; i < arr.size(); i++) {
        //     arr[i-1] -> next = arr[i];
        // } 
        
        inOrder(root);
        root = d -> next;
        
        
    }
};
