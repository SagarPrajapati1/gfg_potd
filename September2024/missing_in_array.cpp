class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& array) {

        int sum = 0;
        for(int i = 0; i < array.size(); i++) {
            sum+= array[i]; 
        }
        return (n*(n+1)/2) - sum;
    }
};
