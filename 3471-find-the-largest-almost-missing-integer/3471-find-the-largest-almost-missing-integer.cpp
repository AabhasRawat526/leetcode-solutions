class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        /*
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
        for (auto id:f){
            if (id.second ==1){
                maximum=max(maximum,id.first);
            }
        }
        return maximum;
        */
        int n=nums.size();
        unordered_map<int,int>f;
        int maxelement=-1;
        for (int i=0;i<n;i++){
            f[nums[i]]++;
        }
        if (k==n){
            return *max_element(nums.begin(),nums.end());
        }
        else if (k==1){
            int ans=-1;
            for (auto id:f){
                if (id.second == 1){
                    ans=max(ans,id.first);
                }
            }
            return ans;
        }
        else {
            if (f[nums[0]]==1){
                maxelement=max(maxelement,nums[0]);
            }
            if (f[nums[n-1]]==1){
                maxelement=max(maxelement,nums[n-1]);
            }
        }
        return maxelement;
    }
};