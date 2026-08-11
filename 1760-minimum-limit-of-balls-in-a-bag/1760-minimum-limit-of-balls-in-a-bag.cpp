class Solution {
public:

bool ispossible(vector<int>& nums,int maxOperations,int mid){
    long long int totaloperations=0;
    for (int i=0;i<nums.size();i++){
        totaloperations=totaloperations+nums[i]/mid;
        if (nums[i]%mid==0){
            totaloperations=totaloperations-1;
        }
    }
    if (totaloperations>maxOperations){
        return false;
    }
    return true;
}

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        long long int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if (ispossible(nums,maxOperations,mid)){
                res=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return res;
    }
};