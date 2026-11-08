class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();             // row size
        int m=grid[0].size();          // col size
        vector<int>rowcount(n,0);
        vector<int>colcount(m,0);
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    rowcount[i]++;
                    colcount[j]++;
                }
            }
        }
        int totalcount=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if(grid[i][j]==1 && (rowcount[i]>1 || colcount[j]>1)){
                    totalcount++;
                }
            }
        }
        return totalcount;
    }
};