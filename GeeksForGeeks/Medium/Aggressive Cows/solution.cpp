class Solution {
public:
    bool cowsBePlaced(vector<int>& stalls, int k, int guess) {
        int cow = 1;
        int prevPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - prevPos >= guess) {
                cow++;
                prevPos = stalls[i];

                if (cow == k)
                    return true;
            }
        }

        return false;
    }

    int aggressiveCows(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int low = 1;
        int high = arr.back() - arr.front();

        while (low <= high) {
            int guess = low + (high - low) / 2;

            if (cowsBePlaced(arr, k, guess)) {
                low = guess + 1;      // try a larger minimum distance
            } else {
                high = guess - 1;     // reduce the minimum distance
            }
        }

        return high;
    }
};