class Solution {
public:
int row;
int column;
//vector<vector<int>>direction{{-1,0},{1,0},{0,1},{0,-1}};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int solve(vector<vector<int>> & grid,int i,int j){
    if (i>=row || i<0 || j>=column || j<0 || grid[i][j]==0){
        return 0;
    }
    int originalvalue=grid[i][j];
    grid[i][j]=0;
    int best=0;
    for (int d = 0; d < 4; d++) {
        int ni = i + dx[d];
        int nj = j + dy[d];
        best=max(best,solve(grid,ni,nj));
    }
    grid[i][j]=originalvalue;
    return best+originalvalue;
}


    int getMaximumGold(vector<vector<int>>& grid) {
        row=grid.size();
        column=grid[0].size();
        int maxcount=0;
        for (int i=0;i<row;i++){
            for (int j=0;j<column;j++){
                if (grid[i][j]!=0){
                    maxcount=max(maxcount,solve(grid,i,j));
                }
            }
        }
        return maxcount;
    }
};