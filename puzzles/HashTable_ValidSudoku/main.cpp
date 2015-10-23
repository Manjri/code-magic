class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t size = board.size();
        bool usedRow[9][9] = {false};
        bool usedCol[9][9] = {false};
        bool usedSqr[9][9] = {false};
        
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1; // subtract 1 for 0-based index
                    int k = (i/3)*3 + j/3;    // k maps to a square (0-8)
                    if(usedRow[i][num] || usedCol[j][num] || usedSqr[k][num])
                        return false;
                    usedRow[i][num] = true;
                    usedCol[j][num] = true;
                    usedSqr[k][num] = true;
                }//if
            }//for-j
        }//for-i
        return true;
    }
};