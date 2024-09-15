/* Structure for tree and linked list

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

// This function should return head to the DLL
class Solution {
  public:
    Node*ptr = new Node(-1);
    Node*head = ptr;
    void solve(Node* root) {
        if(root == nullptr) return;
        
        solve(root -> left);
        
        Node* newNode = new Node(root -> data);
        ptr -> right = newNode;
        newNode -> left = ptr;
        ptr = ptr -> right;
        
        solve(root -> right);
    }
    
    Node* bToDLL(Node* root) {
        // code here
        if(root == nullptr) return root;
        solve(root);
        Node*ans = head -> right;
        // cout << head -> data << endl;
        
        free(head);
        ans->left = NULL;
        
        return ans;
        
    }
};
