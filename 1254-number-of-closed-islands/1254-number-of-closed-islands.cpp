class Solution {
public:

int m;
int n;

bool countIsland(vector<vector<int>> & grid,int row,int col){
    if (row >=m || row< 0 || col >=n || col < 0){
        return false;
    }
    if (grid[row][col]==1){    // marked so that we do not visted back 
        return true;
    }
    grid[row][col]=1;
    bool up=countIsland(grid,row-1,col);
    bool down=countIsland(grid,row+1,col);
    bool left=countIsland(grid,row,col-1);
    bool right=countIsland(grid,row,col+1);
    return up && down && left && right;
}

    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();   // for row;
        n=grid[0].size();   // for column;
        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==0){      // only for land ...
                    if (countIsland(grid,i,j)==true){
                        count++;
                    }
                }
            }
        }
        return count;  
    }
};