class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> result(n, -1);

        //stores pairs of (start_time, original_index)
        vector<pair<int, int>> starts(n);
        for(int i = 0; i<n; i++){
            starts[i] = {intervals[i][0], i};
        }

        //sort based on start times
        sort(starts.begin(), starts.end());

        //For eaxh interval , binary search for the smallest start>=end
        for(int i = 0; i<n; i++){
            int target = intervals[i][1];

            //Binary search to find the first start >= target
            auto it = lower_bound(starts.begin(), starts.end(), make_pair(target, -1),[](const pair<int, int>& a, const pair<int,int>&b){
                return a.first < b.first;
            });

            if(it != starts.end()){
                result[i] = it->second;
            }
        }
        return result;
    }
};