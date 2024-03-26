class Solution {
    public:
    int length(int n)
    {
        int len=0;
        while(n)
        {
            len++;
            n/=10;
        }
        return len;
    }
    bool help(string s,int i,int first,int second)
    {
        //base case
        if(i>=s.length())
        return 0;
        
        //recursive calls
        //and small calculation
        if(first!=-1 and second!=-1)
        {
            int add=first+second;
            int len=length(add);
            int num=0;
            int j=i;
            while(j<s.length() and j<(i+len))
            {
                num*=10;
                num+=(s[j]-'0');
                j++;
            }
            
            if(num!=add)
            return 0;
            
            if(j==s.length())
            return 1;
            
            return help(s,j,second,num);
        }
        
        int num=0;
        for(int j=i;j<s.length();j++)
        {
            num*=10;
            num+=(s[j]-'0');
            
            if(first!=-1)
            {
                bool call=help(s,j+1,first,num);
                if(call)
                return 1;
            }
            else
            {
                bool call=help(s,j+1,num,second);
                if(call)
                return 1;
            }
        }
        return 0;
    }
    bool isAdditiveSequence(string n) {
        return help(n,0,-1,-1);
    }
};


// 2nd solution
bool isAdditiveSequence(string str) {
        // Your code here
        int n = str.size();
        if(n<3)
            return 0;
            
        string ans,s1;
        
        for(int i=0;i<min(n-1,10);i++){
            s1.push_back(str[i]);
            string s2 = "";
            for(int j=i+1;j<min(n,10);j++){
                s2.push_back(str[j]);
                ans = s1+s2;
                int a = stoi(s1);
                int b = stoi(s2);
                while(ans.size()<n){
                    int sum = a+b;
                    string s = to_string(sum);
                    if(n-ans.size() < s.size())
                        break;
                    ans += s;
                    a=b;
                    b=sum;
                    if(ans == str)
                        return 1;
                }
            }
        }
        
        return 0;
    }
