class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int bestfinding=nums[0];
        int res=nums[0];
        int sum=nums[0];
        int minres=nums[0];
        int minfinding=nums[0];
        for (int i=1;i<n;i++){
            sum=sum+nums[i];
            int v1=bestfinding+nums[i];
            int v2=nums[i];
            bestfinding=max(v1,v2);
            res=max(res,bestfinding);
            int v3=minfinding+nums[i];
            int v4=nums[i];
            minfinding=min(v3,v4);
            minres=min(minres,minfinding);
        }
        if (res<0){
            return res;
        } 
        return max(res,(sum-minres)); 
    }
};