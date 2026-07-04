class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        int left=0;
        int right;
        /*
        for (int i=0;i<1;i++){
            left=0;
            right=sum-nums[i]-left;
            if (left==right){
                return 0;
            }
        }
        */
        right=sum-nums[0];
        if (left==right){
            return 0;
        }
        for (int i=1;i<n;i++){
            left=left+nums[i-1];
            right=sum-nums[i]-left;
            if (left==right){
                return i;
            }
        }
        return -1;
    }
};