class Solution {
public:

bool isvalid(vector<vector<char>> & board,int row,int column,char d){
    for (int i=0;i<9;i++){
        if (board[row][i]==d){    // row validity -->> to check if the number that we are going to place in the ith position is it there if there so return false... in simpler words Is d already present anywhere in this row?
            return false;
        }
        if (board[i][column]==d){   // column validity  -->> to check if the number that we are going to place in the ith position is it there so return false .....  in simpler words 
            return false;
        }
        int start_i=row/3*3;
        int start_j=column/3*3;
        for (int k=0;k<3;k++){
            for (int l=0;l<3;l++){
                if (board[start_i+k][start_j+l]==d){
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    for (int i=0;i<9;i++){   // for row
        for (int j=0;j<9;j++){  // for column
            if (board[i][j]=='.'){
                for (char d='1';d<='9';d++){   // we have choices
                    if (isvalid(board,i,j,d)){
                        board[i][j]=d;
                        if (solve(board)==true){  // we are able to make the sudoko 
                            return true;
                        }
                        board[i][j]='.';  // backtrack
                    }
                }
                return false;  // if we are not able to make sudoko if all the cases fails ....
            }
        }
    }
    return true;  // if the sudoko is already filled...
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


// tc is constant as we are iterating 9 times max in the sudoko ....