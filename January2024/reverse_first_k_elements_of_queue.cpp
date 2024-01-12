class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        if(k == 0) return q;
        
        list<int> v;
        while(k > 0){
            v.push_back(q.front());
            q.pop();
            k--;
        }
        
        reverse(v.begin(), v.end());
        while(!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }        
        
        while(!v.empty()) {
            q.push(v.front());
            v.pop_front();
        }
        return q;
    }
};
