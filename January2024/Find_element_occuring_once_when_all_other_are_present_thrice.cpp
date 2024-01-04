class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // unordered_map<int, int> count;
        
        // for(int i = 0; i < N; i++) {
        //     count[arr[i]]++;
        // }
        
        // for(auto it : count) {
        //     if(it.second == 1) return it.first;
        // }
        
        int cnt = 0;
        int ans = 0;
        
        for(int i = 0; i < 32; i++) {
            cnt = 0;
            for(int j = 0; j < N; j++) {
                if((arr[j] >> i) & 1 == 1) cnt++;
            }
            if(cnt % 3 == 1) ans += 1 << i; 
        }
        return ans;
    }
};
