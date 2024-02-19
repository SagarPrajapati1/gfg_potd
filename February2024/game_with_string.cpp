
class Solution{
public:
    int minValue(string s, int k){
        // code here
        unordered_map<char, int> mp;
        
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        
        vector<int>dp;
        
        for(auto it:mp){
            dp.push_back(it.second);
        }

        sort(begin(dp),end(dp));
        
        int sum = 0;
        int n = mp.size();
        while(k > 0 && dp[n-1] > 0){
            dp[n-1]--;
            sort(dp.begin(), dp.end());
            k--;
        }
        
        for(int i = 0; i < n; i++){
            sum += dp[i] * dp[i];
        }
        return sum;
    }


// 2nd solution
int minValue(string s, int k){
      priority_queue < int > pq;
        unordered_map<char,int> mp;
        for(auto ch:s)
        mp[ch]++;
        
        for(auto it:mp)
        {
            pq.push(it.second);
        }
        while(k--)
        {
            int cur = pq.top();
            pq.pop();
            cur--;
            if(cur>0)
            pq.push(cur);
        }
        int ans = 0 ;
        while(!pq.empty())
        {
            int cur = pq.top();pq.pop();
            ans+=(cur*cur);
        }
        return ans;
}
