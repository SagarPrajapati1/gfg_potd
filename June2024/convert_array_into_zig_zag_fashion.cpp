class Solution {
  public:
    void zigZag(int n, vector<int> &arr) {
        for (int i = 0; i < n-1; i++) {
            if (i&1) {
                // odd index -> arr[i] > arr[i+1]
                if (arr[i] < arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                }
            }
            else {
                // even index -> arr[i] < arr[i+1]
                if (arr[i] > arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                }
            }
        }
    }
};
