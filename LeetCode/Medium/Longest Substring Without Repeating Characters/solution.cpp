class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>distincts;
        int low = 0, high = 0, len = 0, res = 0;
        while(high < s.size()){
            distincts[s[high]]++;
            while(distincts[s[high]] > 1){
                distincts[s[low]]--;
                if(distincts[s[low]] == 0){
                    distincts.erase(s[low]);
                }
                low++;
            }
            len = high - low + 1;
            res = max(res, len);
            high++;
        }
        return res;
    }
};