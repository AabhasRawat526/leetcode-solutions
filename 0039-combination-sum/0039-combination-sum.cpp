class Solution {
public:

void helperfunction(vector<int> & candidates,int target,int n,vector<int> &diary,vector<vector<int>> &result,int idx,int sum){
    if (idx==n){
        if (sum==target){
            result.push_back(diary);
        }
        return;
    }
    helperfunction(candidates,target,n,diary,result,idx+1,sum); // nahi lena
    if (sum+candidates[idx]<=target){
        diary.push_back(candidates[idx]);
        sum=sum+candidates[idx];
        helperfunction(candidates,target,n,diary,result,idx,sum);
        sum=sum-candidates[idx];
        diary.pop_back();
    }
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>diary;
        vector<vector<int>>result;
        helperfunction(candidates,target,n,diary,result,0,0);
        return result;
    }
};