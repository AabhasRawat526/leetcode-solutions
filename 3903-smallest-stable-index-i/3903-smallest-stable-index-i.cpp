class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            int minvalue=INT_MAX;
            int maxvalue=INT_MIN;
            for (int j=0;j<=i;j++){    // for max element
                maxvalue=max(maxvalue,nums[j]);
            }
            for (int j=i;j<=n-1;j++){  // for min element
                minvalue=min(minvalue,nums[j]);
            }
            int difference=maxvalue-minvalue;
            if (difference<=k){
                return i;
            }
        }
        return -1;
    }
};