class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        unordered_map<char,int>nextValidSeat;
        for(auto &task : tasks){
            mp[task]++;
            nextValidSeat[task] = 1;
        }
        priority_queue< pair<int, char> >pq;
        for(auto &p : mp){
            pq.push({p.second, p.first});
        }
        int seats = 1;
        while(!pq.empty()){
            vector< pair<int, char> >pulled;
            while(!pq.empty()){
                pair<int, char>p = pq.top();
                pq.pop();
                int child = p.second;
                int freq = p.first;
                if(nextValidSeat[child] <= seats){
                    if(freq > 1){
                        pq.push({freq - 1, child});
                        nextValidSeat[child] = seats + n + 1;
                    }
                    break;
                }
                else{
                    pulled.push_back(p);
                }
            }
            for(auto &p : pulled){
                pq.push(p);
            }
            seats++;
        }
        return seats - 1;
    }
};