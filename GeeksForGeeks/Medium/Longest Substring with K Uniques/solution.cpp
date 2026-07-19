class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int>distincts;
        int low = 0, high = 0, res = 0, len = 0;
        while(high < s.length()){
            distincts[s[high]]++;
            while(distincts.size() > k){
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
        if(distincts.size() < k){
            return -1;
        }
        return res;
    }
};