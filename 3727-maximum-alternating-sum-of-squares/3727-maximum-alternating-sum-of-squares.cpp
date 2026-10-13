class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        for (int i=0;i<n;i++){
            result.push_back(nums[i]*nums[i]);
        }
        sort(result.begin(),result.end());
        int m=result.size();
        long long int small=accumulate(result.begin(),result.begin()+m/2,0LL);
        long long int large=accumulate(result.begin()+m/2,result.end(),0LL);
        return (large-small);
    }
};