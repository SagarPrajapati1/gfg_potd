class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            if (mp[arr[i]] > 0) {
                return true; //return true if the current element already exists in the map
            }

            mp[arr[i]]++; //add current element to the map

            if (i >= k) {
                mp[arr[i - k]]--; // Remove the element that's outside the k-distance
            }
        }
        return false;
    }
};
