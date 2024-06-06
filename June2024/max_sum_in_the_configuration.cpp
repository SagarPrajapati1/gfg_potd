class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long S_0 = 0;
        long long sum_a = 0;
        for (int i = 0; i < n; ++i) {
            S_0 += i * a[i];
            sum_a += a[i];
        }
        
        // Initialize the maximum sum with the initial sum
        long long max_sum = S_0;
        
        // Calculate the sum for other rotations and update the maximum sum
        long long current_sum = S_0;
        for (int i = 1; i < n; ++i) {
            current_sum = current_sum + sum_a - n * a[n-i];
            max_sum = std::max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};
class Solution {
  public:
    long long max_sum(int a[], int n) {
         long long s1 = 0;
            long long ts = 0;
            
            for (int i = 0; i < n; i++) {
                s1 += (long long)i * a[i];  
                ts += (long long)a[i];      
            }
            
            long long maxi = s1;
            
            
            for (int i = n - 1; i >= 1; i--) {
                s1 = s1 + ts - (long long)n * a[i];  
                if (maxi < s1) {
                    maxi = s1;
                }
            }
            
            return maxi;
    }
