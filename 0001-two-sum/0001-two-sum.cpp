class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> f;
        for (int i=0;i<n;i++){
            int difference=target-nums[i];
            if (f.find(difference)!=f.end()){
                return {f[difference],i};
            }
            else {
                f[nums[i]]=i;
            }
        }
        return {};
    }
};