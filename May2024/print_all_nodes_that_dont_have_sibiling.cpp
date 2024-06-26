/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */


void solve(Node* node, vector<int> &ans){
    if(node == NULL) return;
    
    if(node -> left && !node -> right) ans.push_back(node -> left -> data);
    
    if(!node -> left && node -> right) ans.push_back(node -> right -> data);
    
    solve(node -> left, ans);
    solve(node -> right , ans);
}

vector<int> noSibling(Node* node)
{
    // code here
    vector<int> ans;
    solve(node, ans);
    
    if(ans.size() == 0) return {-1};
    
    sort(ans.begin(), ans.end());
    return ans;
}
