class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        
        // int i,x,y;
        // int freq[N+1];
        // vector<int>res;
        // memset(freq,0,sizeof(freq));
        // for(i=0;i<N+2;i++){
        //     freq[arr[i]]++;
        //     if(freq[arr[i]] >= 2)
        //         res.push_back(arr[i]);
        // }
        // return res;
        
        vector<int>v;
        for(int i=0;i<n+2;i++){
           if(arr[abs(arr[i])]<0)v.push_back(abs(arr[i]));
           else arr[abs(arr[i])]= -arr[abs(arr[i])];
        }
        return v;
    }
};
