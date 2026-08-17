class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>> >pq;
        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }
        string res;
        for(auto &pair : mp){
            pq.push({pair.second, pair.first});
        }
        queue<pair<int, char> >q;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            q.push({pq.top().first - 1, pq.top().second} );
            pq.pop();
            if(q.size() > 1){
                if(q.front().first > 0){
                    pq.push(q.front());
                }
                q.pop();
            }
        }
        while(!q.empty() ){
            if(q.front().first != 0){
                return "";
            }
            q.pop();
        }
        return res;
    }
};