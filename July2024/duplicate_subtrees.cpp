class Solution {
  public:
    unordered_map<string, int> m;
    vector<Node*> v;
    string solve(Node *r) {
        if(!r) return "";
        
        string x = solve(r->left) + "," + to_string(r->data) + "," + solve(r->right);
        
        ++m[x];
        
        if(m[x] == 2) v.push_back(r);
        
        return x;
    }
    vector<Node*> printAllDups(Node *r) {
        return solve(r), v;
    }
};
