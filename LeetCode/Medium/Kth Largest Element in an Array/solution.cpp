class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int group = nums.size() - k + 1;
        for(int i = 0; i < group; i++){
            pq.push(nums[i]);
        }
        for(int i = group; i < nums.size(); i++){
            if(nums[i] >= pq.top()){
                continue;
            }
            pq.pop();
            pq.push(nums[i]);
        }
        return pq.top();
    }
};