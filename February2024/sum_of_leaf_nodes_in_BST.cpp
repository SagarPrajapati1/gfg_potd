struct Node{
    int data;
    Node *left,*right;
}; */


class Solution
{
    void solve(Node* root, int &sum){
        if(root == nullptr) return;
        
        if(root -> left == nullptr && root -> right == nullptr) {
            sum = sum + root -> data;
        }
        
        if(root -> left) solve(root -> left, sum);
        if(root -> right) solve(root -> right, sum);
    }
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
            int sum = 0;
            solve(root, sum);
            return sum;
        }
};
