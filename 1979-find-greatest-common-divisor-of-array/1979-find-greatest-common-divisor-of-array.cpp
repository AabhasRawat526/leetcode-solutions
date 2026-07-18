class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int maximum=INT_MIN;
        for (int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
        }
        int minimum=INT_MAX;
        for (int i=0;i<n;i++){
            minimum=min(minimum,nums[i]);
        }
        return gcd(maximum,minimum);
    }
};