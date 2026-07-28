class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int>mp;
        vector<pair<char,int>>order;
        for(int i = 0; i < s.size(); i++){
            if(mp.count(s[i]) == 0){
                order.push_back({s[i], i});
                mp[s[i]] = order.size() - 1;
            }
            else{
                order[mp[s[i]]].second = -1;
            }
        }
        for(const auto &pair : order){
            if(pair.second != -1){
                return pair.second;
            }
        }
        return -1;
    }
};