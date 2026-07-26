class Solution {
public:
    bool allcharpres(vector<int>&have, vector<int>&need){
        for(int i = 0; i < 58; i++){
            if(have[i] < need[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int low = 0, high = 0, len = INT_MAX, reslen = INT_MAX, st = 0;
        vector<int>have(58);
        vector<int>need(58);
        for(int i = 0; i < t.size(); i++){
            need[t[i] - 'A']++;
        }
        while(high < s.size()){
            have[s[high] - 'A']++;
            while(allcharpres(have, need)){ // jb tk info shi h usko or shi kro
                len = high - low + 1;
                if(len < reslen){
                    reslen = len;
                    st = low;
                }
                have[s[low] - 'A']--;
                low++;
            }
            high++;
        }
        if(reslen == INT_MAX){
            return "";
        }
        return s.substr(st, reslen);
    }
};