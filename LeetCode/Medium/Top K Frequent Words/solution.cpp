class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int>mp;
        for(auto &word : words){
            mp[word]++;
        }
        vector<pair<int, string>>ans;
        vector<string>kans;
        for(auto &pair : mp){
            ans.push_back({pair.second, pair.first});
        }
        // greater<pair<int, string>>obj;
        struct compare{
            bool operator()(pair<int, string> &a, pair<int, string> &b){
                if(a.first != b.first)
                    return a.first > b.first;
                return a.second < b.second;
            }
        };
        sort(ans.begin(), ans.end(), compare());
        for(int i = 0; i < k ; i++){
            kans.push_back(ans[i].second);
        }
        return kans;
    }
};