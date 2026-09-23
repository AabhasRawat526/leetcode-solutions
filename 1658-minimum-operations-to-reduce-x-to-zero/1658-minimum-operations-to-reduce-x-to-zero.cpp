class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>f;
        int sum=0;
        f[0]=-1;
        for (int i=0;i<n;i++){
            sum=sum+nums[i];
            f[sum]=i;
        }
        if (sum<x){
            return -1;
        }
        int remainingsum=sum-x;
        int longestSubarray=INT_MIN;
        sum=0;
        for (int i=0;i<n;i++){
            sum=sum+nums[i];
            int findsum=sum-remainingsum;
            if (f.find(findsum)!=f.end()){
                int idx=f[findsum];
                longestSubarray=max(longestSubarray,i-idx);
            }
        }
        if (longestSubarray==INT_MIN){
            return -1;
        }
        return n-longestSubarray;     // here i am solving for the sum-x and if i get the sum-x so eventually we will get the final elements n-(sum-x)
    }
};