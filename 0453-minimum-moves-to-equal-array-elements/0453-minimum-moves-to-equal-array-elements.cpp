class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minelement=*min_element(nums.begin(),nums.end());
        int n=nums.size();
        int operations=0;
        for (int i=0;i<n;i++){
            operations+=abs(minelement-nums[i]);
        }
        return operations;
    }
};