class Solution {
public:
int result=INT_MIN;
int m;

void solve(int idx,int count,int m,vector<int>& resultants,vector<vector<int>>& requests){
    // base case 
    if (idx==m){
        bool allzero=true;
        for (int &zero:resultants){
            if(zero!=0){
                allzero=false;
                break;
            }
        }
        if (allzero==true){
            result=max(result,count);
        }
        return;
    }
    // backtracking ....
    int from=requests[idx][0];
    int to=requests[idx][1];
    resultants[from]++;
    resultants[to]--;
    solve(idx+1,count+1,m,resultants,requests);
    resultants[from]--;
    resultants[to]++;
    solve(idx+1,count,m,resultants,requests);
}

    int maximumRequests(int n, vector<vector<int>>& requests) {
        m=requests.size();
        vector<int>resultants(n,0);
        solve(0,0,m,resultants,requests);
        return result;
    }
};