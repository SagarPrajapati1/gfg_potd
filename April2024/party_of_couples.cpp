
class Solution{
    public:
    int findSingle(int n, int arr[]){
        // code here
        
        // TLE
        // unordered_map<int, int> count;
        // for(int i = 0; i < n; i++){
        //     count[arr[i]]++;
        // }
        

        // for(auto i: count){
        //     if(i.second % 2 != 0) return i.first;
        // }
        
        
        // unordered_set<int> single;
        // for (int i = 0; i < N; i++) {
        //     if (single.find(arr[i]) == single.end()) {
        //         single.insert(arr[i]);
        //     } else {
        //         single.erase(arr[i]);
        //     }
        // }
        // return *single.begin();
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans ^ arr[i];
        }
        return ans;

    }
};
