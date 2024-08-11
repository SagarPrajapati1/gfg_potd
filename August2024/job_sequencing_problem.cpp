/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job &job1, Job &job2){
        return job1.profit > job2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n){ 
        sort(arr, arr+n, comp);
        int profit = 0, cnt = 0, maxtime = -1;
        
        for(int i=0; i<n; i++){
            maxtime = max(maxtime, arr[i].dead);
        }
        
        vector<int> jobs(maxtime+1, -1);
        for(int i=0; i<n; i++){
            
            for(int j = arr[i].dead; j > 0; j--){
                if(jobs[j] == -1){
                    cnt++;
                    jobs[j] = arr[i].id;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, profit};
    } 
};
