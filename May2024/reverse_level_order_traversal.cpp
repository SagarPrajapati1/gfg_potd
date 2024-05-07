/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    
    if(root == NULL) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* front = q.front();
        
        q.pop();
        ans.push_back(front -> data);
        if(front -> right) q.push(front -> right);
        if(front -> left) q.push(front -> left);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
