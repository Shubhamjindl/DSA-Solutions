class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size(), -1);
        for(int i = arr.size() -1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(arr[i]);
                continue;
                
            }
            if(st.top() > arr[i]){
                ans[i] = st.top();
                st.push(arr[i]);
            }
        }
        return ans;
        
    }
};