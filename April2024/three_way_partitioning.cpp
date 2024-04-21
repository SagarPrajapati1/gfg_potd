class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here
        // brute force solution
        // sort(array.begin(),array.end());
        
        // better solution
        // int n = array.size();
        // vector<int> temp1;
        // vector<int> temp2;
        // vector<int> temp3;
        // for(int i = 0; i < n; i++){
        //     if(array[i] < a) temp1.push_back(array[i]);
        //     else if(array[i] >= a && array[i] <= b) temp2.push_back(array[i]);
        //     else temp3.push_back(array[i]);
        // }
        
        // int ind = 0;
        // for(int i = 0; i < temp1.size(); i++){
        //     array[ind++] = temp1[i];
        // }
        
        // for(int i = 0; i < temp2.size(); i++){
        //     array[ind++] = temp2[i];
        // }
        
        // for(int i = 0; i < temp3.size(); i++){
        //     array[ind++] = temp3[i];
        // }
        
        
        
        // optimal solution
        //Using two pointers which help in finding the index with which
    //the elements need to be swapped if they are not in correct position. 
        int n = array.size();
        int start = 0, end = n-1;
     
        for (int i=0; i<=end;)
        {
            //If current element is smaller than lower range, we swap 
            //it with value on next available smallest position. 
            if (array[i] < a)
                swap(array[i++], array[start++]);
     
            //If current element is greater than higher range, we swap 
            //it with value on next available greatest position. 
            else if (array[i] > b)
                swap(array[i], array[end--]);
            
            //Else we just move ahead in the array.
            else
                i++;
        
        }
    }
};
