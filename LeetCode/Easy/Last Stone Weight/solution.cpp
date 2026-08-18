class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto &stone : stones){
            pq.push(stone);
        }
        while(!pq.empty()){
            int afterColsnWt = pq.top();
            pq.pop();
            if(pq.size() == 0){
                return afterColsnWt;
            }
            afterColsnWt -= pq.top();
            pq.pop();
            if(afterColsnWt > 0){
                pq.push(afterColsnWt);
            }
        }
        return 0;
    }
};