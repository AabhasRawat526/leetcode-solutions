class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if (n==1){
            return nums[0];
        }
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if (nums[mid]>nums[right]){
                left=mid+1;
            }
            else if(nums[mid]<nums[right]){
                right=mid;
            }
            else {
                right--;
            }
        }
        return nums[left];
    }
};