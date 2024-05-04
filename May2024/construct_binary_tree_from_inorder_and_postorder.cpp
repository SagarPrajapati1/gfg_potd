struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    
    Node* solve(int in[], int post[], int is, int ie, int ps, int pe){
        
        if(pe < 0 || is > ie) return NULL;
        
        Node* root = new Node(post[pe]);
        int ind = is;
        
        for(; ind <= ie; ind++){
            if(root -> data == in[ind]) break;
        }
        
        int left = ind - is;
        int right = ie - ind;
        
        root -> left = solve(in, post, is, ind-1, ps, ps + left - 1);
        root -> right = solve(in, post, ind + 1, ie, pe - right, pe - 1);
        
        return root;
    }

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        return solve(in, post, 0, n-1, 0, n-1);
    }
};
