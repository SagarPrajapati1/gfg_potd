/* A binary tree Node

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


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      if(root == nullptr) return {};
      queue<Node*> q;
      q.push(root);
      vector<int> ans;
      while(!q.empty()) {
          Node* front = q.front();
          q.pop();
          
          ans.push_back(front->data);
          if(front -> left) q.push(front -> left);
          if(front -> right) q.push(front -> right);
      }
      return ans;
    }
