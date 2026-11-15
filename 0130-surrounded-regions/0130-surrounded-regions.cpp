class Solution {
public:

int x[4]={1,-1,0,0};
int y[4]={0,0,-1,1};

bool isvalid(int m,int n,int i,int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void solve(vector<vector<char>>& board,int n,int m,int i,int j){
    board[i][j]='#';
    for (int k=0;k<4;k++){
        int newrow=i+x[k];
        int newcol=j+y[k];
        if (isvalid(m,n,newrow,newcol) && board[newrow][newcol]=='O'){
            solve(board,n,m,newrow,newcol);
        }
    }
    return;
}


    void solve(vector<vector<char>>& board) {
        int n=board.size();                    // for row
        int m=board[0].size();                 // for column
        for (int j=0;j<m;j++){                 // for the first row
            if (board[0][j]=='O'){
                solve(board,n,m,0,j);
            }
        }
        for (int j=0;j<m;j++){                 // for the last row  
            if (board[n-1][j]=='O'){
                solve(board,n,m,n-1,j);
            }
        }
        for (int i=0;i<n;i++){                 // for the first col
            if (board[i][0]=='O'){
                solve(board,n,m,i,0);
            }
        }
        for (int i=0;i<n;i++){                // for the last col
            if (board[i][m-1]=='O'){
                solve(board,n,m,i,m-1);
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]=='#'){
                    board[i][j]='O';
                }
                else {
                    board[i][j]='X';
                }
            }
        }
        board;
    }
};