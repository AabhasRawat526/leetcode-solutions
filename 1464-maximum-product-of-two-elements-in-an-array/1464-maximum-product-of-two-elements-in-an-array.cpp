class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max1=*max_element(nums.begin(),nums.end());
        auto id=max_element(nums.begin(),nums.end());
        nums.erase(id);
        int max2=*max_element(nums.begin(),nums.end());
        auto it=max_element(nums.begin(),nums.end());
        nums.erase(it);
        return (max1-1)*(max2-1);
    }
};