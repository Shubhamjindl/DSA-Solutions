class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < score.size(); i++){
            pq.push({score[i], i});
        }
        vector<string>res(score.size());
        vector<string>ranks(3);
        ranks[0] = "Gold Medal";
        ranks[1] = "Silver Medal";
        ranks[2] = "Bronze Medal";
        
        int i = 0;
        while(!pq.empty() && i < 3){
            res[pq.top().second] = ranks[i];
            pq.pop();
            i++;
        }

        i = 4;
        while(!pq.empty()){
            res[pq.top().second] = to_string(i);
            pq.pop();
            i++;
        }
        return res;
    }
};