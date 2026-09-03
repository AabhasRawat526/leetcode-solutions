class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minimumnumber=*min_element(nums1.begin(),nums1.end());
        if (minimumnumber%2==1){
            return true;   // me odd me convert kar sakta hu 
        }
        for (int &num:nums1){
            if (num%2==1){
                return false;
            }
        }
        return true;
    }
};