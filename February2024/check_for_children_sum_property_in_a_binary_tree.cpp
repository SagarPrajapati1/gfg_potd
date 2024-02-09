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

class Solution{
    public:

  // using recursion
    bool solve(Node* root){
        
        // 1st case root is null
        if(root == nullptr) return 1;
        
        // 2bd case both children are null
        if(root -> left == nullptr and root -> right == nullptr) return 1;
        
        // 3rd case if one child is null
        if(root -> left == nullptr ){
            if(root -> data != root -> right -> data) return 0;
        }
           
        if(root -> right == nullptr) {
            if(root -> data != root -> left -> data) return 0;
        }
        
        int l = (root -> left != nullptr) ? root -> left -> data : 0;
        int r = (root -> right != nullptr) ? root -> right -> data : 0;
        
        // if
        // {
        //     return true;
        // }
        
        // else return false;
        
        return ((root -> data == (l + r)) && solve(root -> left) && solve(root -> right));
    }

// using bfs
    int solve1(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front == NULL){
                if(!q.empty()) q.push(NULL);
            }
            
            int sum = 0;
            if(front -> left) {
                q.push(front -> left);
                sum += front -> left -> data;
            }
            if(front -> right){
                q.push(front-> right);
                sum += front -> right -> data;
            }
            
            if(sum != front -> data && sum != 0) return 0;
        }
        return 1;
    }
    
    
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     return (int) solve(root);
     
    }
};
