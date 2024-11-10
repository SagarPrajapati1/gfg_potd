class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
         vector<int>v;
        int i=0,j=0;
        int n1=a.size();
        int n2=b.size();
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                v.push_back(a[i]);
                i++;
            }
            else if(a[i]>b[j]){
                v.push_back(b[j]);
                j++;
            }
            else{
                v.push_back(a[i]);
                i++;
                j++;
            }
        }
        while(i<n1){
            v.push_back(a[i]);
            i++;
        }
        while(j<n2){
            v.push_back(b[j]);
            j++;
        }
        return v;
    }
};
