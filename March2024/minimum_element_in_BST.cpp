
class Solution {
  public:
    int min = 0;
    int solve(Node* root){
        if(!root -> left) return root -> data;
        if(!root) return 0;
        
        if(root -> left){
            min = root -> left -> data;
            solve(root -> left);
        }

    }
    
    int minValue(Node* root) {
        // Code here
        // min = solve(root);
        // return min;
        if(root -> left == nullptr) return root -> data; 
        return minValue(root -> left);
    }
};
