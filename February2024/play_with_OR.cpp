
int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    // int ans[n] = {0};
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i-1] | arr[i];
    }
    return arr;
    
}
