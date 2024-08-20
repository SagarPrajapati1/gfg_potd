/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    private:
    void mapParents(Node* root, unordered_map<Node*, Node*>& parentMap, int target, Node*& targetNode) {
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            // Locate the target node
            if (node->data == target) {
                targetNode = node;
            }
            
            // Map the parent for left and right children
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap) {
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool burned = false;
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                // Check left child
                if (node->left && !visited[node->left]) {
                    burned = true;
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                // Check right child
                if (node->right && !visited[node->right]) {
                    burned = true;
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                // Check parent
                if (parentMap[node] && !visited[parentMap[node]]) {
                    burned = true;
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }
            }
            
            if (burned) {
                time++;
            }
        }
        
        return time;
    }
  public:
    int minTime(Node* root, int target) 
    {
         unordered_map<Node*, Node*> parentMap;
        Node* targetNode = nullptr;
        
        // Function to map parents and locate the target node
        mapParents(root, parentMap, target, targetNode);
        
        // Perform BFS from the target node to find the maximum burn time
        return burnTree(targetNode, parentMap);
        
    }
};
