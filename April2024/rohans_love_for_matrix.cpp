  public:
    int firstElement(int n) {
        // code here
        if(n == 0) return 0;
        
        int mod = 1e9+7;
        vector<long long> vec = {1, 1, 1, 0};
        for(int i = 1; i < n; i++){
            long long p1 = (vec[0]+vec[1])%mod;
            long long p2 = (vec[2]+vec[3])%mod;
            
            vec[1] = vec[0];
            vec[3] = vec[2];
            vec[0] = p1;
            vec[2] = p2;
        }
        return vec[2];
    }
};
