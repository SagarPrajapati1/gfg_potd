class Solution {
  public:
    string roundToNearest(string str) {
        int n=str.size();
        
        int a=str[n-1]-'0';
        if(a==0)
        return str;
        
        if(10-a >= a)
        str[n-1]='0';
        else 
        {
            str[n-1]='0';
            int carry=1;
            for(int i=n-2;i>=0 && carry>0 ;i--)
            {
                int t=str[i]-'0';
                int dig=t+carry;
                str[i]=dig%10+'0';
                carry=dig/10;
            }
            if(carry==1)
            {
                str.insert(str.begin(),carry+'0');
            }
        }
        
        return str;
        
    }
};