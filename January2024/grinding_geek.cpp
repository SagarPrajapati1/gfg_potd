class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        vector<int> temp(total + 1);
        for(int i = n-1; i>= 0; i--) {
            for(int j = total; j >= 0; j--) {
                if(j >= cost[i]) {
                    temp[j] = max(temp[j], 1 + temp[j - 0.1 * cost[i]]);
                }
            }
        }
        
        return temp[total];
    }
};
