/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* solve(vector<int> &nums, int s, int e){
        if(s > e) return NULL;
        
        int mid = (s + e) / 2;
        
        Node*root = new Node(nums[mid]);
        root-> left = solve(nums, s, mid-1);
        root -> right = solve(nums, mid+1, e);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
        
    }
};
