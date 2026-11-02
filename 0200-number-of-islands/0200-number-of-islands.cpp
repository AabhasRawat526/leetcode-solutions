class Solution {
public:

int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

int count=0;

bool isvalid(int x,int y,int n,int m){
    return x>=0 && x<n && y>=0 && y<m;
}

void solveusingdfs(vector<vector<char>>& grid,int n,int m,int i,int j){
    grid[i][j]='0';
    for (int k=0;k<4;k++){
        int newrow=i+x[k];
        int newcol=j+y[k];
        if (isvalid(newrow,newcol,n,m) && grid[newrow][newcol]=='1'){
            solveusingdfs(grid,n,m,newrow,newcol);
        }
    }
    return;
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();      // for rows
        int m=grid[0].size();   // for column
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j]=='1'){
                    solveusingdfs(grid,n,m,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};