class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            if (arr[i]==arr[i-1]){
                arr[i-1]=arr[i-1]*2;
                arr[i]=0;
            }
        }
        vector<int> v;
        for(auto i:arr){
            if (i!=0){
                v.push_back(i);
            }
        }
        for(auto i:arr){
            if (i==0){
                v.push_back(i);
            }
        }
        // v.push_back(n);
        return v;
    }
};
