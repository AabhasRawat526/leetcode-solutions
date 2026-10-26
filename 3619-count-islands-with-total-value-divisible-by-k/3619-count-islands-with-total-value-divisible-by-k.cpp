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

// A new function call starts. It has its own separate sum variable. now sum becomes 1 when that sum next elements found out to be 0 so it returns to the function and the value is 1 so 2 + 1 = 3 then for 5 same it has a own sum variable now sum becomes 5 which is another variable when it found that it's next element is 0 so it returns the sum to the original function and in the function contains the value 5 3 + 5 in this way 8 comes as an answer ......