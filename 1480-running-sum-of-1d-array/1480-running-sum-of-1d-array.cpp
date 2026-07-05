class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        /*
        vector <int> arr;
        int sum=0;
        for (int i=0;i<n;i++){
            sum=sum+nums[i];
            arr.push_back(sum);
        }
        return arr;
        */
        int sum=0;
        for (int i=0;i<n;i++){
            sum=sum+nums[i];
            nums[i]=sum;
        }
        return nums;
    }
};