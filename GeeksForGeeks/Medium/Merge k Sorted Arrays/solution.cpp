class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        using p = pair<int,pair<int,int> >;
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int>res;
        priority_queue< p, vector<p> , greater<p> >pq;
        for(int i = 0; i < rows; i++){
            pq.push({mat[i][0], {i,0} });
        }
        for(int i = 0; i < rows*cols; i++){
            res.push_back(pq.top().first);
            pair<int,int> curridx = pq.top().second;
            pq.pop();
            if(curridx.second + 1 < cols){
                pq.push({mat[curridx.first][curridx.second + 1], {curridx.first, curridx.second + 1} });
            }
        }
        return res;
    }
};