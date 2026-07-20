class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>res;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()){
            int st1 = firstList[i][0];
            int end1 = firstList[i][1];
            int st2 = secondList[j][0];
            int end2 = secondList[j][1];
            if(st1 < st2){ // ideal case
                if(end1 >= st2){
                    res.push_back({max(st1, st2), min(end1, end2)});
                }
            }
            else{
                if(end2 >= st1){
                    res.push_back({max(st1, st2), min(end1, end2)});
                }
            }
            if(end1 <= end2){
                i++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};