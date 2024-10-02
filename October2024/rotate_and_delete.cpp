class Solution {
  public:
    int rotateDelete(vector<int> &arr) {
        // Your code here
        // int k = 1;
        // while(arr.size() > 1){
        //     int n = arr.size();
            
        //     // rotate
        //     int val = arr[n-1];
        //     for(int i = n-1; i >= 0; i--) {
        //         arr[i] = arr[i-1];
        //     }
        //     arr[0] = val;
            
        //     if(k >= arr.size()){
        //         // delete first element
        //         for(int i = 0; i < n; i++) {
        //             arr[i] = arr[(i+1)%n];
        //         }
        //         arr.pop_back();
        //     }
        //     else {
        //         for(int i = n-k; i < n-1; i++) {
        //             swap(arr[i], arr[i+1]);
        //         }
        //         arr.pop_back();
        //     }
        //     k++;
        //     if(arr.size() == 1) return arr[0];
        //     // for(int i = 0; i < arr.size(); i++) cout << arr[i] << "  ";
        // } // TLE
        // return -1;
        
         int k = 1;
        
        while(arr.size() > 1){
            arr.insert(arr.begin(),arr[arr.size()-1]);
            arr.pop_back();
            
            int remove_ind = arr.size()-k;
            
            if(remove_ind < 0){
                remove_ind = 0;
            }
            arr.erase(arr.begin()+remove_ind);
            k++;
        }
        return arr[0];
    }
};
