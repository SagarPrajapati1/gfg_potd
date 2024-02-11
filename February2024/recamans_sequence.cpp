class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        
        unordered_set<int>st;
        st.insert(0);
        vector<int>ans;
        ans.push_back(0);
        int prev=0;
        for(int i=1; i<=n; i++){
            int temp=prev-i;
            if(temp<0 || st.find(temp)!=st.end()){
                temp=prev+i;
            }
            st.insert(temp);
            ans.push_back(temp);
            prev=temp;
        }
        return ans;
        
    }
};
