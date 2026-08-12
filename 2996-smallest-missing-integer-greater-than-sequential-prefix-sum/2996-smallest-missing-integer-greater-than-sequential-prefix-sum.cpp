class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for (int i=1;i<n;i++){
            if (nums[i]==nums[i-1]+1){
                res.push_back(nums[i]);
            }
            else {
                break;
            }
        }
        int m=res.size();
        int sum=0;
        for (int i=0;i<m;i++){
            sum=sum+res[i];
        }
        vector <int> ans(n);
        for (int i=0;i<n;i++){
            ans[i]=nums[i];
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++){
            if (sum==ans[i]){
                sum++;
            }
        }
        return sum;
    }
};