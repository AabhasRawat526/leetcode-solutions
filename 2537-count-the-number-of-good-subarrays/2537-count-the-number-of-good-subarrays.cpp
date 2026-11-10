class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_map<int,int>f;
        long long int result=0;
        long long int pair=0;
        while(j<n){
            pair=pair+f[nums[j]];
            f[nums[j]]++;
            while(pair >= k){
                result=result+n-j;
                f[nums[i]]--;
                if (f[nums[i]]==0){
                    f.erase(nums[i]);
                }
                pair=pair-f[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};