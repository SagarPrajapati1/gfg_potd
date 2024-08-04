class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({start[i], end[i]});
        }
        
        sort(vec.begin(), vec.end(), [](auto& v1, auto& v2){
            if(v1.second == v2.second) return v1.first < v2.first;
            return v1.second < v2.second;
        });
        
        int ans = 1;
        int j = 0;
        for(int i = 1; i < n; i++){
            if(vec[j].second < vec[i].first){ 
                j = i;
                
                ans++;
                
            }
        }
        return ans;
    }
};
