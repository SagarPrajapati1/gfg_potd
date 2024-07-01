// TLE Solution O(N^2) and O(1)
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
        int sum = 0;
        for(int i = 0; i < n; i++) {
            
            sum = 0;
            
            for(int j = i; j < n; j++) {
                
                sum += arr[j];
                
                if(sum == s) {
                    return {i+1, j+1};
                }
                
            }
        }
        return {-1};
    }
};


// O(N) and O(1)
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        
        long long sum=0;
        int j=0;
        for(int i = 0; i < n; i++) {
           sum += arr[i];
           while(sum > s && j < i) {
               sum -= arr[j++];
           }
           if(sum == s){
               return{j+1, i+1};
           }
        }
             return {-1};
    }
};
