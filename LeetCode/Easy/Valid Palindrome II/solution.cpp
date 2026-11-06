class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return match(s, left+1, right) || match(s, left, right - 1);
            }
            left++; right--;
        }
        return true;
    }
    bool match(string s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++; right--;
        }
        return true;
    }
};