class Solution {
public:
    vector<int> matrixDiagonally(vector<vector<int>>& mat) {

        //Your code here
         vector<int>v1;
         int n=mat.size();
         n=n-1;
         for(int i=0;i<=2*n;i++){
             for(int j=0;j<=i;j++){
                 if(i-j<=n && j<=n){
                     if(i%2==0){
                         v1.push_back(mat[i-j][j]);
                     }
                     else{
                         v1.push_back(mat[j][i-j]);
                     }
                 }
             }
         }
         return v1;

// 2nd solution
        bool ok = true;
        int n = mat.size();
        vector<int> res, r;
        if(n == 0)    return {};
        int m = mat[0].size();
        for(int i= 0;i<m;i++){
            int ii = 0;
            int jj = i;
            vector<int> res;
            while(ii < n && ii >= 0 && jj >= 0 && jj < m){
                if(ok)  res.insert(res.begin(), mat[ii][jj]);
                else    res.push_back(mat[ii][jj]);
                ii++;
                jj--;
            }
            for(int x : res)    r.push_back(x);
            ok = !ok;
        }
        for(int i = 1;i<n;i++){
            int ii = i;
            int jj = m - 1;
            vector<int> res;
            while(ii < n && ii >= 0 && jj >= 0 && jj < m){
                if(ok)  res.insert(res.begin(), mat[ii][jj]);
                else    res.push_back(mat[ii][jj]);
                ii++;
                jj--;
            }
            for(int x : res)    r.push_back(x);
            ok = !ok;
        }
        return r;
    }
};
