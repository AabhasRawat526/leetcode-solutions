class Solution {
public:

int t[201][1001];

int solve(int idx,int target,vector<int>& nums){
    if (idx==nums.size() || target<0){
        return 0;
    }
    if (target==0){
        return 1;
    }
    if (t[idx][target]!=-1){
        return t[idx][target];
    }
    int take_index=solve(0,target-nums[idx],nums);
    int reject_index=solve(idx+1,target,nums);
    return t[idx][target]=take_index+reject_index;
}

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,target,nums);
    }
};


// whenever in backtracking i will face tle it means that the question is asking to memoize it so memoize it ....