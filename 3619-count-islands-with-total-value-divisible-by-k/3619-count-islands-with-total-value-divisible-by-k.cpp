class Solution {
public:

int m ;
int n ; 

vector<vector<int>>direction={{0,1},{0,-1},{1,0},{-1,0}};

long long int solve(vector<vector<int>>& grid,int row,int col){
    long long int sum=grid[row][col];
    grid[row][col]=0;

    for (vector<int>&dir:direction){
        int i_ = row + dir[0];
        int j_ = col + dir[1];

        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0){
            sum = sum + solve(grid,i_,j_);
        }
    }
    return sum;
}

    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] > 0){
                    long long int sum=solve(grid,i,j);
                    if ((sum%k)==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};