// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:

void dfs(Node* curr, Node *node, vector<Node*> &vis){
    
    vis[node->val] = node;
    
    for(auto it : curr->neighbors){
        
        if(vis[it->val] == nullptr){
            
            Node *newNode = new Node(it->val);
            (node->neighbors).push_back(newNode);
            dfs(it, newNode, vis);
            
        }
        else {
            (node->neighbors).push_back(vis[it->val]);
        }
    }
}


    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        
        vector<Node*> vis(10000, NULL);
        
        Node* newNode = new Node(node->val);
        
        // vis[node->val] = newNode;
        
        dfs(node, newNode, vis);
        
        // for(auto it : node -> neighbors){
        //     if(vis[it->val] == nullptr){
        //         Node* curr = new Node(newNode -> val);
        //         (newNode->neighbors).push_back(curr);
                
        //     }
        //     else {
        //         (newNode->neighbors).push_back(vis[it->val]);
        //     }
        // }
        return newNode;
    }
};
