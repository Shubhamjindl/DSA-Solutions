class Solution {
public:
    float distance(vector<int>&points){
        return sqrt(points[0] * points[0] + points[1] * points[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>, vector<pair<float,int>>, less<pair<float,int>> >pq;
        for(int i = 0; i < points.size(); i++){
            pq.push({distance(points[i]), i});
            if(pq.size() > k){
                pq.pop(); // max from k + 1 is removed
            }
        }
        vector<vector<int>> kclosestPoints;
        while(pq.size() > 0){
            kclosestPoints.push_back(points[pq.top().second]);
            pq.pop();
        }
        return kclosestPoints;
    }
};