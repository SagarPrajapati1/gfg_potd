class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> p;
        for(auto it: arr){
            p.push(it);
            if(p.size() > k){
                p.pop();
            }
        }
        return p.top();
    }
};
