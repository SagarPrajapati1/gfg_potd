class Solution {
  public:
    int isPossible(vector<int> &arr, int k, int mid) {
        int pageSum = 0;
        int StCnt = 1;
        
        for(int i = 0; i < arr.size(); i++) {
            
            if(pageSum + arr[i] <= mid){
                pageSum += arr[i];
            }
            else {
                StCnt++;
                pageSum = arr[i];
            }
        }
        return StCnt;
    }
  
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int sum = 0;
        int ans = -1;
        for(auto i: arr) sum += i;
        
        int s = *max_element(arr.begin(), arr.end());
        int e = sum;
        
        while(s <= e) {
            int mid = (s+e)/2;
            int stCnt = isPossible(arr, k, mid);
            if(stCnt > k) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        if(arr.size() < k) return -1;
        return s;
    }
};
