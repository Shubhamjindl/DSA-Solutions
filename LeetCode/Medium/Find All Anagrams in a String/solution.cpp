class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>sMap;
        unordered_map<char, int>pMap;
        vector<int>ans;
        if(p.size() > s.size()){
            return ans;
        }
        int low = 0;
        for(int i = 0; i < p.size(); i++){
            sMap[s[i]]++;
            pMap[p[i]]++;
        }
        if(sMap == pMap) ans.push_back(low);
        for(int high = p.size(); high < s.size(); high++){
            sMap[s[low]]--;
            if(sMap[s[low]] == 0){
                sMap.erase(s[low]);
            }
            low++;
            sMap[s[high]]++;
            if(sMap == pMap){
                ans.push_back(low);
            }
        }
        return ans;
    }
};