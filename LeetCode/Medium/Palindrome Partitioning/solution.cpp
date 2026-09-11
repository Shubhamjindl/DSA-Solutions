class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>diary;
        recBT(res, diary, s, 0);
        return res;
    }
    bool palindrome(string &s, int st, int end){
        if(st == end || st > end){
            return true;
        }
        bool corresCharPalindrome = false;
        if(s[st] == s[end]){
            corresCharPalindrome = true;
        }
        bool restCharPalindrome = palindrome(s, st + 1, end - 1);
        if(restCharPalindrome && corresCharPalindrome){
            return true;
        }
        return false;
    }
    void recBT(vector<vector<string>> &res, vector<string>&diary, string&s, int st){
        if(st == s.size()){
            res.push_back(diary);
            return;
        }
        for(int end = st; end < s.size(); end++){
            if(!palindrome(s, st, end))
            continue;
            diary.push_back(s.substr(st, end - st + 1));
            recBT(res, diary, s, end + 1);
            diary.pop_back();
        }
    }
};