class Solution {
public:

long long int findcost(vector<int>& nums,vector<int>& cost,long long int target){

    long long int result=0;

    for (int i=0;i<nums.size();i++){

        result=result +(long long)abs(nums[i]-target)*cost[i];
    }

    return result;
}


    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long int left=*min_element(nums.begin(),nums.end());
        long long int right=*max_element(nums.begin(),nums.end());
        long long int result=INT_MAX;
        while(left<=right){
            long long mid=left+(right-left)/2;
            long long int cost1=findcost(nums,cost,mid);
            long long int cost2=findcost(nums,cost,mid+1);
            result=min(cost2,cost1);

            if (cost2>cost1){
                right=mid-1;
                result=min(cost2,cost1);
            }
            else {
                left=mid+1;
                result=min(cost2,cost1);
            }
        }
        if(result==INT_MAX){
            return 0;
        }
        return result;
    }
};