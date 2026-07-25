class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i < asteroids.size(); i++){
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0 && -asteroids[i] > st.top()){
                st.pop();
            }
            if(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                if(st.top() == -asteroids[i]){
                    st.pop();
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int>ans(st.size());
        for(int i = ans.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
        
    }
};