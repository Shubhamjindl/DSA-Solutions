class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        unordered_map<char,int>need;
        unordered_map<char,int>mp;
        for(const char &ch : s){
            need[ch]++;
        }
        for(const char &ch : text){
            mp[ch]++;
        }
        int res = INT_MAX;
        for(int i = 0; i < s.size(); i++){
            int charMaxCnt = mp[s[i]]/need[s[i]];
            res = min(res, charMaxCnt);
        }
        
        return res;
    }
};