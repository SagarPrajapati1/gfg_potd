class Solution{
public:
    void solve1(vector<int> &arr, int i, int k, vector<int> &temp, vector<vector<int>> &ans){
        if(i == arr.size()){
            if(k == 0){
                ans.push_back(temp);
                
            }
            return;
        }
        
        if(arr[i] <= k){
            temp.push_back(arr[i]);
            solve1(arr, i+1, k-arr[i], temp, ans);
            temp.pop_back();
        }
        
        int j = 0;
        while(j+i < arr.size() && arr[i] == arr[j+i]) j++;
        
        solve1(arr, i+j, k, temp, ans);
       
    }

    void solve2(vector<int> &arr, int ind, int target, vector<int>& temp, vector<vector<int>> &ans){
        
            if(target == 0) 
            {
                ans.push_back(temp);
                return;
            }
        
        for(int j = ind; j < arr.size(); j++){
            
            if(j > ind && arr[j] == arr[j-1]) continue;
            
            if(target < arr[j]) break;
            
            temp.push_back(arr[j]);
            solve2(arr, j+1, target - arr[j], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(arr.begin(), arr.end());
        solve2(arr, 0, k, temp, ans);
        
        
        // solve1(arr, 0, k, temp, ans);
        return ans;
    }
};
