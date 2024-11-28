class Solution {
  public:
    int myAtoi(char *s) {
        int n=strlen(s);
        int sign=1;
        int i=0;
       const int MAX=pow(2,31)-1;
       const int MIN=-pow(2,31);
        //ignoring white spaces
        while((i<n)&&(s[i]==' ')){
           i++;
        }
        if((i<n)&&(s[i]=='-'||s[i]=='+')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        long long ans=0;
        while(i<n&&s[i]>='0'&&s[i]<='9'){
                ans=ans*10+(s[i]-'0');
                if(sign==-1&&-ans<MIN)return MIN;
                if(sign==1&&ans>MAX)return MAX;
        i++;
        }
        return ans*sign;
    }
};
