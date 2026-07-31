class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return true;
            }
            if (nums[mid]==nums[right]){
                right--;
                continue;
            }
            if(nums[mid]>nums[right]){   // part 1 and part2 me divide kar diya...
                
                if (nums[mid]<target){  //part1 me increasing so target bada hoga so nums[mid] chota
                    left=mid+1;
                }
                else {
                    if (nums[0]>target){   // part 1 ke according 
                        left=mid+1;
                    }
                    else {
                        right=mid-1;
                    }
                }
            }
            else {
                if (nums[mid]>target){ //part2 me divide kar diya so chota so target wo chota and nums[mid] bada
                    right=mid-1;
                }
                else {
                    if (nums[right]<target){
                        right=mid-1;
                    }
                    else {
                        left=mid+1;
                    }
                }
            }
        }
        return false;
    }
};