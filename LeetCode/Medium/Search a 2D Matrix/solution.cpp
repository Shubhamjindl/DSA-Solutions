class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int matrixSize = matrix.size() * matrix[0].size();
        int low = 0, high = matrixSize - 1;
        while(low <= high){
            int guess = low + (high - low)/2;
            int guessRow = guess / matrix[0].size();
            int guessCol = guess % matrix[0].size();
            if(matrix[guessRow][guessCol] == target){
                return true;
            }
            else if(target > matrix[guessRow][guessCol]){
                low = guess + 1;
            }
            else{
                high = guess - 1;
            }
        }
        return false;
    }
};