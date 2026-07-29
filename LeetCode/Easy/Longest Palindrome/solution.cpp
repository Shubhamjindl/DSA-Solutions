class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int len = 0;
        for(char &ch : s){
            mp[ch]++;
        }
        bool first = 1;
        for(auto &ch : mp){
            if(ch.second % 2 == 0){
                len += ch.second;
            }
            else{
                
                if(first){
                    len += ch.second;
                    first = false;
                }
                else{
                    int pairs = ch.second/2;
                    len += 2 * pairs;
                }
            }
        }
        return len;
    }
};