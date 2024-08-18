class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum1=0,sum2=0;
        int i=0,j=arr.size()-1;
        while (i<=j){
            if(sum1>=sum2) sum2+=arr[j--];
            else sum1+=arr[i++];
        }
        return (sum1==sum2);
    }
};
