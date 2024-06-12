class Solution {
  public:
    bool check(int n){
        while(n!=0){
            int t = n%10;
            if(t==4){
                return true;
            }
            n /=10;
        }
        return false;
    }
    int countNumberswith4(int n) {
        // code here
        int c=0;
        for(int i=1;i<=n;i++){
            if(check(i)){
                c++;
            }
        }
        return c;
    }
};
