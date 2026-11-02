class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // tc is 0(nlogn)
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=nums[n/2];
        int moves=0;
        //for (int i=0;i<n;i++){
            //moves+=abs(mid-nums[i]);
        //}
        for (int i=0;i<n/2;i++){
            moves=moves+abs(nums[i]-mid);
            moves=moves+abs(nums[n-i-1]-mid);
        }
        return moves;
    }
};