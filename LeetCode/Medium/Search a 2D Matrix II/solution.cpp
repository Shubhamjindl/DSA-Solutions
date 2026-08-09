class Solution {
public:
    bool bs(int &col, int &row, vector<vector<int>>& matrix, int target){
        if(target == matrix[row][col])
            return true;
        
        else if(target > matrix[row][col])
            col++;
        
        else
            row--;
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = rows - 1, col = 0;
        while(col < cols && row >= 0){
            if(bs(col, row, matrix, target)){
                return true;
            }
        }
        return false;
    }
    
};