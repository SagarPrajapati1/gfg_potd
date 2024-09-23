class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<int> v(2);
        
        long long sum = 0;
        long long sumOfSquare = 0;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            sumOfSquare += (long long) arr[i] * arr[i];
        }
        
        long long realSum = (long long)n*(n+1)/2;
        long long realSumOfSquare = (long long)n * (n+1) *(2*n+1)/6;
        
        
        long long diffSum = realSum - sum;
        long long diffSquareSum = realSumOfSquare - sumOfSquare;
        
        
        int m = (int)((diffSquareSum - diffSum*diffSum)/ (2*diffSum));
        int d = (int)(m+diffSum);
        
        v[0] = m;
        v[1] = d;
        return v;
        
    }
};
