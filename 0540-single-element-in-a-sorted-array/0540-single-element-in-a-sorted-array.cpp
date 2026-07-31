class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int mid=(left+right)/2;
            bool iseven;
            if ((right-mid)%2==0){
                iseven=true;
            }
            else {
                iseven=false;
            }
            if (nums[mid]==nums[mid+1]){
                if(iseven){
                    left=mid+2;
                }
                else{
                    right=mid-1;
                }
            }
            else {
                if(iseven){
                    right=mid;
                }
                else{
                    left=mid+1;
                }
            }
        }
        return nums[right];
    }
};