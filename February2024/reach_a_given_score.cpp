  vector<long long>v(n+1 , 0);
        v[0] = 1;
        for(int i = 3 ; i < n+1 ; i++){
            v[i] = v[i] + v[i-3];
        }
        for(int i = 5 ; i < n+1 ; i++){
            v[i] = v[i] + v[i-5];
        }
        for(int i = 10 ; i < n+1 ; i++){
            v[i] = v[i] + v[i-10];
        }
        return v[n] ; 
