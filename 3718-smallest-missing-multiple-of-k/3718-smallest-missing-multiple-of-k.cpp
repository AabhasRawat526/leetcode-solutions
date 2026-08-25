class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        set <int> s;
        int j=1;
        for (int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int m=s.size();
        for (auto id:s){
            if ((id)==k*j){
                j++;
            }
        }
        return k*j;
    }
};