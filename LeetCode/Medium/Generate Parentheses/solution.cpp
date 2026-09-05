class Solution {
public:
    vector<string> result;

    void bt(string &ans, int n, int open, int close) {

        if(ans.size() == 2 * n) {
            result.push_back(ans);
            return;
        }

        if(open < n) {
            ans.push_back('(');
            bt(ans, n, open + 1, close);
            ans.pop_back();
        }

        if(close < open) {
            ans.push_back(')');
            bt(ans, n, open, close + 1);
            ans.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string ans;
        bt(ans, n, 0, 0);
        return result;
    }
};