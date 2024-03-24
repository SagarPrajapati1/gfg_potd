
class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        
        int i = 0;
        vector<int> ans(st.size());
        while(!st.empty()) {
            ans[i++] = (st.top());
            st.pop();
        }
        
        // if(st.top() == -1){
            
        // }
        st.push(x);
        i = ans.size();
        
        int n = ans.size();
        while(!ans.empty()){
            st.push(ans[i-1]);
            ans.pop_back();
            i--;
        }
        
        return st;
    }
};
