class Solution {
public:

int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

bool isvalid(int newrow,int newcol,int n,int m){
    return newrow>=0 && newrow<n && newcol>=0 && newcol<m;
}

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();                    // for row;
        int m=grid[0].size();                 // for col;
        queue<pair<int,int>> q;
        int time=0;
        int fresh=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-2;
                }
                else if (grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while (!q.empty() && fresh > 0){
            time++;
            int s=q.size();
            while(s--){
                pair<int,int> t=q.front();
                int pair1=t.first;
                int pair2=t.second;
                q.pop();
                for (int k=0;k<4;k++){
                    int newrow=pair1+x[k];
                    int newcol=pair2+y[k];
                    if (isvalid(newrow,newcol,n,m) && grid[newrow][newcol]==1){
                        grid[newrow][newcol]=-2;
                        q.push({newrow,newcol});
                        fresh--;
                    }
                }
            }
        }
        if (fresh > 0){
            return -1;
        }
        return time;
    }
};