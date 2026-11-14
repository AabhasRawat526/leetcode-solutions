class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n =nums.size();
        int maxsum=INT_MAX;
        for(int k=l;k<=r;k++){
            int sum=0;
            for (int i=0;i<k;i++){
                sum=sum + nums[i];
            }
            if (sum > 0){
                maxsum=min(maxsum,sum);
            }
            int i=0;
            int j=k;
            while(j<n){
                sum=sum+nums[j];
                sum=sum-nums[i];
                if (sum>0){
                    maxsum=min(maxsum,sum);
                }
                i++;
                j++;
            }
        }
        if (maxsum==INT_MAX){
            return -1;
        }
        return maxsum;
    }
};