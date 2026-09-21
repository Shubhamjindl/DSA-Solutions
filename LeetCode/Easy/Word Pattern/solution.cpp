class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string> words;
        while(ss >> word){
            words.push_back(word);
        }
        unordered_map<char,string>mp1;
        unordered_map<string,char>mp2;
        if(words.size() != pattern.size()){
            return false;
        }
        for(int i = 0; i < pattern.size(); i++){
            char ch = pattern[i];
            word = words[i];
            if(mp1.count(ch) || mp2.count(word)){
                if(mp1[ch] != word || mp2[word] != ch){
                    return false;
                }
            }
            mp1.insert({ch, word});
            mp2.insert({word, ch});
        }
        return true;
    }
};