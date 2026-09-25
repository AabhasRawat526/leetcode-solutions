class Solution {
public:
int result;
int K;


void solve(int idx,vector<int>& nums,unordered_map<int,int>& f){
    if (idx==nums.size()){
        result++;
        return;
    }
    solve(idx+1,nums,f);     // not take if i do not want to take that element then i will do this so that i can explore the next element..

    if (f.find(nums[idx]+K)==f.end() && f.find(nums[idx]-K)==f.end()){
        f[nums[idx]]++;
        solve(idx+1,nums,f);
        f[nums[idx]]--;
        if (f[nums[idx]]==0){
            f.erase(nums[idx]);
        }
    } 
}

    int beautifulSubsets(vector<int>& nums, int k) {
      result=0;
      K=k;
      unordered_map<int,int>f;
      solve(0,nums,f);
      return result-1;    // if i simply do result that means i am also including empty subset so i have to substract -1 so that i do not get the empty subset...  
    }
};