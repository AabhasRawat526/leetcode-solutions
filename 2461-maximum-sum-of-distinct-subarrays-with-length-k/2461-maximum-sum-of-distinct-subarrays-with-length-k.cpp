class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        unordered_set<int>st;
        long long int result=0;
        long long int currentwindowsum=0;
        int n=nums.size();
        while(j<n){
            while(st.count(nums[j])){
                currentwindowsum=currentwindowsum-nums[i];
                st.erase(nums[i]);
                i++;
            }
            currentwindowsum=currentwindowsum+nums[j];
            st.insert(nums[j]);
            if (j-i+1==k){
                result=max(result,currentwindowsum);
                currentwindowsum=currentwindowsum-nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};