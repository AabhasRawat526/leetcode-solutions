class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int sum=0;
        for (int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        int right=(sum-nums[0]-left);
        if (left==right){
            return 0;
        }
        for (int i=1;i<n;i++){
            left=left+nums[i-1];
            int right=(sum-left-nums[i]);
            if (left==right){
                return i;
            }
        }
        return -1;
    }
};