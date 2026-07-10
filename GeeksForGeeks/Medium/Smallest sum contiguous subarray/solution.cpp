class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        int bestending = a[0], ans = a[0];
        for(int i = 1; i < a.size(); i++){
            int v1 = bestending + a[i];
            int v2 = a[i];
            bestending = min(v1, v2);
            ans = min(ans, bestending);
        }
        return ans;
        
    }
};
