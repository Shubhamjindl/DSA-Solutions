class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct compare{
            bool operator()(pair<int, int> &a, pair<int,int> &b){
                if(a.first != b.first)
                    return a.first > b.first;
                return a.second > b.second;
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare>pq;
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto &pair : mp){
            int element = pair.first;
            int freq = pair.second;
            if(pq.size() < k){
                pq.push({freq, element});
                continue;
            }
            if(pq.top().first < freq){
                pq.pop();
                pq.push({freq, element});
            }
        }
        vector<int>ans;
        for(int i = 0; i < k ; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};