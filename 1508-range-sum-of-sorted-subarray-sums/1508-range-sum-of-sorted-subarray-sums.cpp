class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // brute force;
        int M=1e9+7;
        int m=nums.size();
        vector<int> temp;
        for (int i=0;i<m;i++){
            int sum=0;
            for (int j=i;j<m;j++){
                sum=sum+nums[j];
                temp.push_back(sum);
            }
        }

        sort(temp.begin(),temp.end());
        long long int res=0;   // here left and right is based on the 1 based indexing not on the 0 based indexing
        for (int i=left-1;i<=right-1;i++){
            res=(res+temp[i])%M;
        }
        return res;
    }
};