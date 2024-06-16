class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<bool> prime(n+1, 1);
        prime[0] = 0;
        prime[1] = 0;
        
        // make all non-primes to false
        for(int i = 2; i <= sqrt(n); i++) {
            if(prime[i]){
                for(int j = i*i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        
        int s = 2;
        int e = n;
        // remove all the non primes from start
        while(!prime[e]) e--;
        
        while(s <= e) {
            int sum = s + e;
            if(sum == n) return {s, e};
            else if(sum > n) {
                e--;
                while(!prime[e]) e--;
            }
            else {
                s++;
                while(!prime[s]) s++;
            }
        }
        return {-1, -1};
    }
};



class Solution {
  public:
        bool isPrime(int num) {
            if (num <= 1) return false;
            if (num <= 3) return true;
            if (num % 2 == 0 || num % 3 == 0) return false;
            for (int i = 5; i * i <= num; i += 6) {
                if (num % i == 0 || num % (i + 2) == 0) return false;
            }
            return true;
        }

    
    vector<int> getPrimes(int n) {
         for (int a = 2; a <= n / 2; ++a) {
            int b = n - a;
            if (isPrime(a) && isPrime(b)) {
                return {a, b};
            }
        }
        return {-1, -1};
    }
};
