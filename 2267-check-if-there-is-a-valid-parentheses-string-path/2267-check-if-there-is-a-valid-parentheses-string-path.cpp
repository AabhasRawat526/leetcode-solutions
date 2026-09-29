class Solution {
public:
int row;
int column;
int t[101][101][201];
int solve(int i,int j,int opencount,vector<vector<char>>& grid){
    opencount+=(grid[i][j]=='(')?1:-1;
    if (opencount<0){
        return false;
    }
    if (t[i][j][opencount] != -1) {
        return t[i][j][opencount];
    }
    if (i==row-1 && j==column-1){
        return t[i][j][opencount]=(opencount==0);
    }
    if (i+1<row){
        if (solve(i+1,j,opencount,grid)){
            return t[i][j][opencount]=true;
        }
    }
    if (j+1<column){
        if (solve(i,j+1,opencount,grid)){
            return t[i][j][opencount]=true;
        }
    }
    return t[i][j][opencount]=false;
}
    bool hasValidPath(vector<vector<char>>& grid) {
        row=grid.size();
        column=grid[0].size();
        if ((row+column-1)%2==1){
            return false;
        }
        if (grid[0][0]==')' || grid[row-1][column-1]=='('){
            return false;
        }
        memset(t,-1,sizeof(t));
        return solve(0,0,0,grid);
    }
};