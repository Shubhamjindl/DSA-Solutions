class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            int oddPalin = palinCount(s, i, i);
            int evenPalin = palinCount(s, i, i + 1);
            count += oddPalin + evenPalin;
        }
        return count;
    }
    int palinCount(string &s, int left, int right){
        int count = 0;
        while(left >= 0 && right < s.length()){
            if(s[left] == s[right]){
                count++;
            }
            else break;
            left--; right++;
        }
        return count;
    }
};