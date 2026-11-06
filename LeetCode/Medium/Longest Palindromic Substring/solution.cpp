class Solution {
public:
    string longestPalindrome(string s) {
        int st = 0, reslen = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                if(isPalindrome(s, i, j)){
                    if(j-i+1 > reslen){
                        st = i;
                        reslen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(st, reslen);
    }
    bool isPalindrome(string &s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                if(s[i] != s[j]) return false;
            }
            i++; j--;
        }
        return true;
    }
};