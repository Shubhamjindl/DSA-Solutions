class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size(), -1);
        int idx = nums.size() -1;
        nums.insert(nums.end(), nums.begin(), nums.end());
        for(int i = nums.size() -1; i > idx; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            if(st.top() > nums[i]){
                st.push(nums[i]);
            }
        }
        for(int i = idx; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            if(st.top() > nums[i]){
                ans[i] = st.top();
                st.push(nums[i]);
            }
        }
        return ans;
    }
};