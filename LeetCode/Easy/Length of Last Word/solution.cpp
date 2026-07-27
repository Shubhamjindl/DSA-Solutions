class Solution {
public:
    int lengthOfLastWord(string s) {
        int end, st, i = s.size() - 1;
        for(i; i >= 0; i--){
            if(s[i] != ' '){
                end = i;
                break;
            }
        }
        for(i = i- 1; i >= 0; i--){
            if(s[i] == ' '){
                st = i;
                break;
            }
        }
        return end - st;
    }
};