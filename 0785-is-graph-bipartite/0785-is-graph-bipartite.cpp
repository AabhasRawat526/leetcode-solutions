class Solution {
public:

int colour=0;

bool result=true;

void dfs(vector<vector<int>> & graph,int colour,vector<int> & color,int node){
    color[node]=colour;
    for (int j=0;j<graph[node].size();j++){
        int neighbour=graph[node][j];
        if (color[neighbour]!=-1 && color[neighbour]==colour){
            result=false;
        }
        if (color[neighbour]==-1){
            dfs(graph,1-colour,color,neighbour);
        }
    }
    return;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for (int i=0;i<n;i++){
            if (color[i]==-1){
                dfs(graph,0,color,i);
            }
        }
        return result;
    }
};