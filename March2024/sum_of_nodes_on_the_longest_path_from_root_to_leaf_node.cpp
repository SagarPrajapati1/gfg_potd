/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:

    int maxSum = 0, mxh = 0;
    
    void solve(Node* root, int h, int sum)
    {   
        // base case
        if(!root){
            if(h > mxh){
                mxh = h;
                maxSum = sum;
            }
            else if(mxh == h) maxSum = max(maxSum, sum);
            return;
        }
        
  
        solve(root -> left, h+1, sum+root -> data);
        solve(root -> right, h+1, sum+root -> data);
        
   
        
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        solve(root, 0, 0);
        return maxSum;
    }
};
