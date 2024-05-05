/*
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        // add code here.
        map<int, vector<int>>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});


        //BFS 
        while(!q.empty()){
            auto x= q.front(); q.pop();
            Node* r= x.first;
            int level= x.second;
            mp[level].push_back(r->data);
            
            if(r->left){
                q.push({r->left, level-1});
            }
            if(r->right){
                q.push({r->right, level+1});
            }
        }

//Calculate sum and store in resultant vector.
        vector<int> res;
        for(auto x: mp){
            vector<int> t= x.second;
           int sum= accumulate(t.begin(), t.end(),0);
           res.push_back(sum);
        }
        return res;
    }
};
