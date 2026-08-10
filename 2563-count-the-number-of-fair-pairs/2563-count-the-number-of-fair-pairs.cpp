class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        long long int count=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<n;i++){
            int lowercount=lower-nums[i];
            auto it=lower_bound(nums.begin()+i+1,nums.begin()+n,lowercount);  // here n is exclusive
            int x=(it-nums.begin())-i-1;
            int uppercount=upper-nums[i];
            auto id=upper_bound(nums.begin()+i+1,nums.begin()+n,uppercount);  // here n is exclusive
            int y=(id-nums.begin())-i-1;
            count=count+abs(y-x);
        }
        return count;
    }
};