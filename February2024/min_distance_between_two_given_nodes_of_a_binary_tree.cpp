struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* solve(Node* root,int a,int b){
        if(root == NULL){
            return NULL;
        }
        if(root->data == a || root->data == b){
            return root;
        }
        
        Node* l = solve(root->left,a,b);
        Node* r = solve(root->right,a,b);
        
        if(l != NULL && r != NULL){
            return root;
        }
        else if(l == NULL && r != NULL){
            return r;
        }
        else if(l != NULL && r == NULL){
            return l;
        }
    }
    pair<int,int> solve2(Node* root,int a){
        if(root == NULL){
            return {0,0};
        }
        if(root->data == a){
            return {1,1};
        }
        
        pair<int,int> l = solve2(root->left,a);
        pair<int,int> r = solve2(root->right,a);
        
        if(l.first == 1 || r.first == 1){
            return {1,l.second+r.second+1};
        }
        else{
            return {0,l.second+r.second};
        }
    }
    int findDist(Node* root, int a, int b) {
        //Step1 = Calculate LCA of a and LCA of b
        //Step2 = Now take out the distance of a and b from the given LCA
        //Step3 = Add the edges from the left and right of LCA
        Node* strt = solve(root,a,b);
        
        int l = (strt->data == a) ? 0: solve2(strt,a).second-1;
        int r = (strt->data == b) ? 0: solve2(strt,b).second-1;
        return l+r;
    }
};
