class Solution{   
public:
    bool isPrime(int n) {
        
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int solve(int num1,int num2)
    {   
      //code here
        unordered_set<int> st;
        queue<int> q;
        
        q.push(num1);
        st.insert(num1);
        
        int lvl = 0;
        while(q.size()) {
            
            int n = q.size();
            while(n--) {
                int num = q.front();
                q.pop();
                
                if(num == num2) return lvl;
                for(int i = 0; i < 4; i++) {
                    
                    int temp = num;
                    int fact = pow(10, i);
                    temp -= (fact * ((temp / fact) % 10));
                    
                    for(int value = 0; value <= 9; value++){
                        temp += (fact * value);
                        
                        if(temp > 1000 && !st.count(temp) && isPrime(temp)) {
                            q.push(temp);
                            st.insert(temp);
                        }
                        temp -=  (fact * value);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
