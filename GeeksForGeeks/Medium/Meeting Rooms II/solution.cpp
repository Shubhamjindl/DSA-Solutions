class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int trains = 0;
        int i = 0, j = 0, res = 0;
        while(i < start.size() && j < end.size()){
            if(start[i] < end[j]){
                trains++;
                res = max(res, trains);
                i++;
            }
            else{
                trains--;
                j++;
            }
        }
        return res;
    }
};
