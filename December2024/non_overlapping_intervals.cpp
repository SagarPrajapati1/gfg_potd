class Solution {
public:
    int minRemoval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Step 1: Sort intervals by their ending time
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) -> bool {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        // Step 2: Initialize variables
        vector<int> last = {-1, -1}; // Stores the last non-overlapping interval
        int cnt = 0; // Counter for the number of intervals to remove

        // Step 3: Iterate through the sorted intervals
        for (vector<int>& x : intervals) {
            if (last[0] == -1) {
                // First interval, no previous interval to compare with
                last = x;
            } else {
                if (last[1] > x[0]) {
                    // Overlap detected, increment removal counter
                    ++cnt;
                    continue;
                } else {
                    // No overlap, update the last interval
                    last = x;
                }
            }
        }

        // Step 4: Return the result
        return cnt;
    }
};
