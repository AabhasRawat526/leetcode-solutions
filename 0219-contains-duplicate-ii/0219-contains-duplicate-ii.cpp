class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_set<int>st;
        while(j<n){
            if (abs(j-i)>k){
                st.erase(nums[i]);
                i++;
            }
            else {
                if(st.find(nums[j])!=st.end()){
                    return true;
                }
                st.insert(nums[j]);
                j++;
            }
        }
        return false;
    }
};