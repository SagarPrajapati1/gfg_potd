class Solution {
  public:
    long long int InternalCount(long long int p[], long long int q[], long long int r[]) {
        long long int area = abs(p[0]*(q[1]-r[1]) + q[0]*(r[1]-p[1]) + r[0]*(p[1]-q[1]));
        long long int b = gcd(p,q) + gcd(q,r) +gcd(r,p);
        return (area-b+2)/2;
    }
    
    long long int gcd(long long int a[], long long int b[]){
        return calculate(abs(a[0]-b[0]), abs(a[1]-b[1]));
    }
    
    long long int calculate(long long int p1,long long int p2){
        while(p2!=0){
            long long int temp=p2;
            p2=p1%p2;
            p1=temp;
        }
        return p1;
    }
};
