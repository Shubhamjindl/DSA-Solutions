class Solution {
  public:
    // Function to remove all occurrences of the character from the string
    void removeCharacter(string &s, char c) {
        rec(s, c, 0);
    }
    void rec(string &s, char c, int idx){
        if(idx == s.size()){
            return;
        }
        if(s[idx] != c){
            rec(s, c, idx + 1);
        }
        else{
            s.erase(s.begin() + idx);
            rec(s, c, idx);
        }
    }
};