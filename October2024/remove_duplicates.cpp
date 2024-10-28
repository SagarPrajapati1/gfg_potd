class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(arr[i]) == mp.end()) {
                mp[arr[i]]++;
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};



int removeDups(vector<int>& vect)
{
    long long int prod = vect[0];
    int res_ind = 1;
    for (int i = 1; i < vect.size(); i++) {
        if (prod % vect[i] != 0) {
            vect[res_ind++] = vect[i];
            prod *= vect[i];
        }
    }
    vect.erase(vect.begin() + res_ind, vect.end());
}
