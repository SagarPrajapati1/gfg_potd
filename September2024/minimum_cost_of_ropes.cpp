class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        
        int n = arr.size();
        long long cost = 0;
        
        for(long long i = 0; i < n; i++) {
            minHeap.push(arr[i]);
        }
        
        while(minHeap.size() > 1) {
            long long sum = 0;
            long long top1 =  minHeap.top();
            sum += top1;
            minHeap.pop();
            
            long long top2 = minHeap.top();
            sum += top2;
            minHeap.pop();
            minHeap.push(sum);
            
            cost += top1 + top2;
            
        }
        return cost;
    }
};
