class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char ch : s){
            if(!st.empty() && st.top().first == ch){
                if(st.top().second >= k -1){
                    st.pop();
                }
                else{
                    st.top().second++;
                }
            }
            else{
                st.push({ch, 1});
            }
        }
        string ans;
        int n = st.size();
        for(int i = 0; i < n; i++){
            while(st.top().second > 0){
                ans.push_back(st.top().first);
                st.top().second--;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};