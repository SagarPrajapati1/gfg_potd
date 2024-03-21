/*Structure of the node of the binary tree is as
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

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	bool flag = true;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	while(!q.empty()) {
    	  
    	    int n = q.size();
    	    vector<int> temp(n);
    	    
    	    for(int i = 0; i < n; i++){
    	        
    	        Node* front = q.front();
    	        q.pop();
    	    
    	        int ind = flag ? i : n-i-1;
    	        temp[ind] = front -> data;
    	        
    	        if(front -> left) q.push(front -> left);
        	    
        	    if(front -> right) q.push(front -> right); 

    	    }
    	    for(auto i : temp) ans.push_back(i);
    	    flag = !flag;
    	}
    	return ans;
    }
};
