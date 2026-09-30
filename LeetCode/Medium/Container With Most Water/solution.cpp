class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxWater = 0;
        while(i < j){
            int water = (j - i) * min(height[j], height[i]);
            if(water > maxWater){
                maxWater = water;
            }
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return maxWater;
    }
};