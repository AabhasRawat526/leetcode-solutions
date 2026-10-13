class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // tc is 0(nlogn) because we are sorting and sc is 0(n) because we are using extra space we are creating an extra array .....
        /*
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
        */

        // other method to reduce the tc is by using nth_element kind of quick sort 

        int n=nums.size();
        for (int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        long long int small=accumulate(nums.begin(),nums.begin()+n/2,0LL);
        long long int large=accumulate(nums.begin()+n/2,nums.end(),0LL);
        return (large-small);
    }
};