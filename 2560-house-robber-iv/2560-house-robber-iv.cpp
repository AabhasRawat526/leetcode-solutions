class Solution {
public:

bool possibletosteal(vector<int> &nums,int mid,int k){
    int house=0;
    for (int i=0;i<nums.size();i++){
        if (nums[i]<=mid){
            house++;
            i++;
        }
    }
    if (house>=k){
        return true;
    }
    return false;
}

    int minCapability(vector<int>& nums, int k) {

        int n=nums.size();
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int result=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possibletosteal(nums,mid,k)){
                result=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return result;
    }
};