class Solution {
  public:
    bool rec(string &s, int first, int last){
        if(first > last){
            return true;
        }
        if(first == last){
            return true;
        }
        bool innerCorres = rec(s, first + 1, last - 1);
        if(s[first] == s[last] && innerCorres){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isPalindrome(string& s) {
        return rec(s, 0, s.size() - 1);
    }
};