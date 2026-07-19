class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
        vector<vector<int>>res;
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        
        for(size_t i = 1; i < intervals.size(); i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            if(end1 >= start2){ //merge
                start1 = start1;
                end1 = max(end1, end2);
            }
            else{
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        res.push_back({start1, end1});
        return res;
    }
    int bs(vector<vector<int>>& intervals, int st, int end, int target){
        while(st <= end){
            int mid = st + (end - st)/2;
            if(target == intervals[mid][0]){
                return mid;
            }
            else if(target < intervals[mid][0]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx = bs(intervals, 0, intervals.size() - 1, newInterval[0]);
        intervals.insert(intervals.begin() + idx, newInterval);
        return mergeInterval(intervals);
    }
};