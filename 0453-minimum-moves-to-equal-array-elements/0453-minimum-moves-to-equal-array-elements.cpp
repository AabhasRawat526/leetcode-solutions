class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minelement=*min_element(nums.begin(),nums.end());
        int n=nums.size();
        int operations=0;
        for (int i=0;i<n;i++){
            operations+=nums[i]-minelement;
        }
        return operations;
    }
};