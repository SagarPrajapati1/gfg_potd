class Solution
{
    public:
    
    void kDistantFromLeafUtil(Node* node,int &counter,bool visited[],int pathLen,int k)
    {
    	//base case
    	if (node==NULL) return;
    
    	visited[pathLen] = false;
    	pathLen++;
    
    	//if it's a leaf node, we increment the count but only if the 
    	//same ancestor at distance k is not already counted.
    	if (node->left == NULL && node->right == NULL &&
    		pathLen-k-1 >= 0 && visited[pathLen-k-1] == false)
    	{
    		counter++;
    		//setting the ancestor as visited so that we won't count it again.
    		visited[pathLen-k-1] = true;
    		return;
    	}
    
    	//if the current node is not a leaf node then we call the function 
    	//recursively for left and right subtrees.
    	kDistantFromLeafUtil(node->left, counter, visited, pathLen, k);
    	kDistantFromLeafUtil(node->right, counter, visited, pathLen, k);
    	
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* node, int k)
    {
    	int counter = 0;
    	bool visited[MAX_HEIGHT] = {false};
    	kDistantFromLeafUtil(node, counter, visited, 0, k);
    	
    	//returning the count.
    	return counter;
    }
};


// 2nd Solution



class Solution
{
    public:
    	vector<Node*> vec;
    	set<Node*> st;
    
    void helper(Node* root, int k){
        if(root == nullptr) return;
        
        vec.push_back(root);
        
        if(root -> left == NULL && root -> right == NULL){
            if(((int)vec.size() - k - 1 )>= 0){
                st.insert(vec[(int)vec.size() - k - 1]);
            }
        }
        
        helper(root -> left, k);
        helper(root -> right, k);
        
        // backtrack
        vec.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here.
    	
    
    	
    	helper(root, k);
    	
    	return (int)st.size();
    	
    }
};
