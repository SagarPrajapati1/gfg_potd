class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        int ans = 0;
        int temp = n;
        // Your code here
        while(temp){
            ans = ans ^ temp;
            temp/= 2;
        }
        return ans;
        
    }
};
