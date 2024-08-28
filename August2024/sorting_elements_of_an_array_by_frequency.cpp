class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int> mp;
        for(auto &it:arr)mp[it]++;
        vector<pair<int,int>> v;
        for(auto &it:mp)v.push_back({it.second,-it.first});
        sort(v.rbegin(),v.rend());
        vector<int> ans;
        for(auto &it:v){
            while(it.first--)ans.push_back(-it.second);
        }
        return ans;
    }
};
