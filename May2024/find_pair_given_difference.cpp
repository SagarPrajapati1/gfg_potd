class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        unordered_map<int,int>m;
        int c=-1;
        for (int i=0;i<n;i++){
            m[arr[i]]=i;
        }
     
        for (int i=0;i<n;i++){
            if (m.find(arr[i]+x)!=m.end()){
                if (m[arr[i]+x]!=i)
                    c=1;
                
            }
        }
        return c;
    }
};
