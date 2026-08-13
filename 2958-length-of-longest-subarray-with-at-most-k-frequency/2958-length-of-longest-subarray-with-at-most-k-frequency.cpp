class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> f;
        int left=0;
        int ans=0;
        for (int right=0;right<n;right++){
            f[nums[right]]++;
            while(f[nums[right]]>k){
                f[nums[left]]--; // we need to shrink the window from the left, because we want to keep the subarray contiguous.
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};