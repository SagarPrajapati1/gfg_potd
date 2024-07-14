class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int s = 0;
        int e = arr.size() - 1;
        
        while(s < e){
            while(arr[s] == 0 && s < e) s++;
            while(arr[e] == 1 && s < e) e--;
            if(s < e) swap(arr[s++], arr[e--]);
        }
    }
};
