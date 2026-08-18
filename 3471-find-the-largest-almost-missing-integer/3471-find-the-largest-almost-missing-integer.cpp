class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if (n==k){
            return *max_element(nums.begin(),nums.end());
        }
        int i=0;
        int j=k-1;
        unordered_map<int,int>f;
        while(j<n){
            for (int l=i;l<=j;l++){
                f[nums[l]]++;
            }
            i++;
            j++;
        }
        int maximum=-1;
        for (auto &id:f){
            if (id.second ==1){
                maximum=max(maximum,id.first);
            }
        }
        return maximum;
    }
};