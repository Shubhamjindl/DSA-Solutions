class Solution {
public:
    int matrixElementsLessEqual(vector<vector<int>>& matrix, int guess){
        int rows = matrix.size(), cols = matrix[0].size(), klessEquals = 0;
        int guessRow = rows - 1, guessCol = 0;
        while(guessRow >= 0 && guessCol < cols){
            if(matrix[guessRow][guessCol] <= guess){
                klessEquals += guessRow + 1;
                guessCol++;
            }
            else
                guessRow--;
        }
        return klessEquals;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0], rows = matrix.size(), cols = matrix[0].size();
        int high = matrix[rows - 1][cols - 1];
        while(low < high){
            int guess = low + (high - low)/2;
            if(matrixElementsLessEqual(matrix, guess) >= k){
                high = guess;
            }
            else{
                low = guess + 1;
            }
        }
        return high;
    }
};