class Solution {
  public:
  
    void inorder(Node* root, vector<int> &in) {
        if(root == nullptr) return;
        
        inorder(root -> left, in);
        in.push_back(root -> data);
        inorder(root -> right, in);
    }
    
    int merge(vector<int> &in, int l, int mid, int r) {
        
        vector<int> v(r - l + 1);
        
        int i = l;
        int m = mid + 1;
        
        int j = 0;
        
        int inv = 0;
        
        while(i <= mid && m <= r) {
            
            if(in[i] <= in[m]) {
                v[j++] = in[i++];
            }else{ 
                
                v[j++] = in[m++];
            
                inv += mid - i + 1;
                
            }
        }
        while(i <= mid){
            v[j++] = in[i++];
        }
        
        while(m <= r){
            v[j++] = in[m++];
        }

        for(int i = l; i <= r; i++){
            in[i] = v[i-l];
        }
        return inv;
    }
    
    int mergeSort(vector<int>& in, int l, int r) {
        
        int inv = 0;
        
        if(l >= r) return inv;
        
       
        int mid = l+(r-l)/2;
            
        inv += mergeSort(in, l, mid);
        inv += mergeSort(in, mid+1, r);
        inv += merge(in, l, mid, r);
      
        return inv;
    }

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int> in;
        
        // inorder traversal
        inorder(root, in);
        
        // inversion count
        int inv = 0;
        
        inv = mergeSort(in, 0, n-1);
        
        return inv;
    }
};
