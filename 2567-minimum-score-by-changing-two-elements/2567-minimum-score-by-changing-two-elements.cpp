class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high1=abs(nums[n-2]-nums[1]);
        int high2=abs(nums[n-1]-nums[2]);
        int high3=abs(nums[n-3]-nums[0]);
        int high=min({high1,high2,high3});
        int score=low+high;
        return score;
    }
};