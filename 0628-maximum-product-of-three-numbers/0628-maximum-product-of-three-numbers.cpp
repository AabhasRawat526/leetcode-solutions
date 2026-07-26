class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        // idea is we can get max product when we multiply first largest*second largest*third largest
        // we can also get max product when we multiply first smallest * second smallest*third smallest.
        sort(nums.begin(),nums.end());
        int product=(nums[n-1]*nums[n-2]*nums[n-3]);
        int product1=(nums[0]*nums[1]*nums[n-1]);
        int maximumproduct=max(product,product1);
        return maximumproduct;
    }
};