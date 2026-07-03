class Solution {
public:
    bool check(int row, int col, vector<vector<char>>& arr){
        for(int i=0; i<9; i++){
            if(row!=i && arr[row][col]==arr[i][col]) return false;
            if(col!=i && arr[row][col]==arr[row][i]) return false;
        }
        int drow = (row/3)*3;
        int dcol = (col/3)*3;

        for(int i=drow; i<drow+3; i++){
            for(int j=dcol; j<dcol+3; j++){
                if(i==row && j==col) continue;
                if(arr[i][j]==arr[row][col]) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.' && !check(i,j,board)) return false;
            }
        }
        return true;
    }
};
