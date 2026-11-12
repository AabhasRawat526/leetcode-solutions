class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int inc=1;
        int dec=1;
        for (int i=0;i<n-1;i++){
            if (nums[i] > nums[i+1]){
                dec++;
            }
            else {
                dec=1;
            }
            if (nums[i] < nums[i+1]){
                inc++;
            }
            else {
                inc=1;
            }
            ans=max(ans,max(inc,dec));
        }
        return ans;
    }
};