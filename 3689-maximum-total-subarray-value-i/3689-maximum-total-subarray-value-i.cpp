class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long int maxelement=*max_element(nums.begin(),nums.end());
        long long int minelement=*min_element(nums.begin(),nums.end());
        long long int difference=maxelement-minelement;
        return difference*k;
    }
};