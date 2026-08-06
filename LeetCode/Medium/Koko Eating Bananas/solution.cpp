class Solution {
public:
    int kokoEatingTime(vector<int>& piles, int guess){
        long long int EatedBananas = 0, hours = 0;
        for(int i = 0; i < piles.size(); i++){
            EatedBananas = piles[i];
            hours += (piles[i] + guess - 1)/guess;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = -1;
        for(int i = 0; i < piles.size(); i++){
            high = max(piles[i], high);
        }
        while(low < high){
            int guess = low + (high - low)/2;
            if(kokoEatingTime(piles, guess) > h){
                low = guess + 1;
            }
            else{
                high = guess;
            }
        }
        return high;
    }
};