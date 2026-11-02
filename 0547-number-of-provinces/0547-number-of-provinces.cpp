class Solution {
public:

int count=0;

int n;

void countProvinces(vector<vector<int>>& isConnected,vector<bool>& visited,int i){
    visited[i]=true;
    for (int j=0;j<n;j++){
        if (!visited[j] && isConnected[i][j]==1){
            countProvinces(isConnected,visited,j);
        }
    }
    return;
}

    int findCircleNum(vector<vector<int>>& isConnected) {
       n=isConnected.size();
       vector<bool>visited(n,false);
       for (int i=0;i<n;i++){
            if (!visited[i]){
                countProvinces(isConnected,visited,i);
                count++;
            }
       }
       return count;
    }
};