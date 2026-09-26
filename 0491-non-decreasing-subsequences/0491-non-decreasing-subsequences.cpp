class Solution {
public:

int n;

void solve(vector<int>& nums,int idx,vector<int>& current,vector<vector<int>>& result){
    if (current.size()>=2){  // base case ...
        result.push_back(current);
    }
    unordered_set<int> s;   // to avoid duplicate element...
    for (int i=idx;i<n;i++){
        if ((current.empty() || nums[i]>=current.back()) && s.find(nums[i])==s.end()){
            current.push_back(nums[i]);
            solve(nums,i+1,current,result);
            current.pop_back();
            s.insert(nums[i]);
        }
    }
}

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> result;
        vector<int> current;
        solve(nums,0,current,result);
        return result;
    }
};