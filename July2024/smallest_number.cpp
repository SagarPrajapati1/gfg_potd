class Solution {
  public:
    string smallestNumber(int s, int d) {
        
        if(d*9<s)return "-1";
        vector<int>v(d,0);
        v[0]=1;
        s--;
        for(int i=d-1;i>=0;i--)
        {
            v[i]+=min(s,9);
            s-=min(s,9);
        }
        string res="";
        for(int i=0;i<d;i++)res+=(v[i]+'0');
        return res;
    }
};
