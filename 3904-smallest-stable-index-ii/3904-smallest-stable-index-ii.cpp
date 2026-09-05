class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minelementindex(n);
        int minvalue=INT_MAX;
        for(int i=n-1;i>=0;i--){
            minvalue=min(minvalue,nums[i]);
            minelementindex[i]=minvalue;
        }
        int maxvalue=INT_MIN;
        for (int i=0;i<n;i++){
            maxvalue=max(maxvalue,nums[i]);
            minvalue=minelementindex[i];
            if ((maxvalue-minvalue)<=k){
                return i;
            }
        }
        return -1;
    }
};