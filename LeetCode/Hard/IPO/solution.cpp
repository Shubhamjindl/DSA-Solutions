class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater< pair<int,int> > >pqMin;
        for(int i = 0; i < capital.size(); i++){
            pqMin.push({capital[i], profits[i]});
        }
        priority_queue<int>pqMax;
        while(k > 0){
            while(!pqMin.empty() && pqMin.top().first <= w){
                pqMax.push(pqMin.top().second);
                pqMin.pop();
            }

            if(pqMax.empty()){
                break;
            }

            w += pqMax.top();
            pqMax.pop();
            k--;
        }
        return w;
    }
};