class Solution {
public:

int n;

void solve(vector<int>& candidates,int target,vector<int>& current,vector<vector<int>>& result,int idx){
    if (target<0){
        return;
    }
    if (target==0){
        result.push_back(current);
    }
    for (int i=idx;i<candidates.size();i++){
        if (i>idx && candidates[i]==candidates[i-1]){
            continue;
        }
        current.push_back(candidates[i]);   // pushing it in the array 
        solve(candidates,target-candidates[i],current,result,i+1); // exploring it 
        current.pop_back(); // we are removing it basically we are reversing the step...
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>current;
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,current,result,0);
        return result;
    }
};