class Solution {
public:

bool isvalid(vector<int> & nums , int count , int x){

    int i=0;

    int counting=0;

    while(i<nums.size()-1){

        if (nums[i+1]-nums[i]<=count){
            i=i+2;
            counting++;
        }
        else {
            i=i+1;
        }
    }

    return counting>=x;

}

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        int res=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isvalid(nums,mid,p)){
                res=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return res;
    }
};