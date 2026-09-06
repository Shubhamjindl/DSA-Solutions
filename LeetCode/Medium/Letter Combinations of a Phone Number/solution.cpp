class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string diary;
        vector<string>letters;
        letters.push_back("");
        letters.push_back("");
        letters.push_back("abc");
        letters.push_back("def");
        letters.push_back("ghi");
        letters.push_back("jkl");
        letters.push_back("mno");
        letters.push_back("pqrs");
        letters.push_back("tuv");
        letters.push_back("wxyz");
        recBT(res, diary, digits, letters, 0);
        return res;
    }
    void recBT(vector<string>&res, string &diary, string &digits, vector<string>&letters, int i){
        if(i == digits.size()){
            res.push_back(diary);
            return;
        }
        string choice = letters[digits[i] - '0'];
        for(int j = 0; j < choice.size(); j++){
            diary.push_back(choice[j]);
            recBT(res, diary, digits, letters, i + 1);
            diary.pop_back();
        }
        return;
    }
};