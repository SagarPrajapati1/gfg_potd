class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    
	   // 1st solution
	   // int cnt = 0;
	    
	   // int ind1 = 0;
	   // int ind2 = 0;
	    
	   // int arr1[n*n] = {0};
	   // int arr2[n*n] = {0};
	    
	   // for(int i = 0; i < n; i++){
	   //     for(int j = 0; j < n; j++) {
	   //         arr1[ind1++] = mat1[i][j];
	   //         arr2[ind2++] = mat2[i][j];
	   //     }
	   // }
	    
	    
	   // ind2 = n*n-1;
	   // int i = 0;
	   // while(i < n*n && ind2 >= 0){
	   //     if(arr1[i] + arr2[ind2] == x) {
	   //         cnt++;
	   //         ind2--;
	   //         i++;
	   //     }
	   //     else if(arr1[i] + arr2[ind2] < x) i++;
	   //     else if(arr1[i] + arr2[ind2] > x) ind2--;
	   // }
	   // return cnt;
	   
	   // 2nd solution
	   //int start=0,end=n*n-1,ans=0;
	   // while(start<(n*n) && end>=0)
	   // {
	   //     if(mat1[start/n][start%n]+mat2[end/n][end%n]>=x)
	   //     {
	   //         if(mat1[start/n][start%n]+mat2[end/n][end%n]==x)
	   //         ans++;
	   //         end--;
	   //     }
	   //     else
	   //     start++;
	   // }
	   // return ans;
	   
	   
	   // 3rd solution
	    int ans = 0;
	    multiset<int> a, b;
	    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) a.insert(mat1[i][j]), b.insert(mat2[i][j]);
	    for(auto &it : a) ans += b.count(x - it);
	    return ans;
	}
};
