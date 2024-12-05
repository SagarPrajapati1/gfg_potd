class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int s = 0, m = 0, e = arr.size() - 1;
        
        while(m <= e) {
            if(arr[m] == 0) swap(arr[s++], arr[m++]);
            else if(arr[m] == 2) swap(arr[m], arr[e--]);
            else m++;
        }
    }
};
