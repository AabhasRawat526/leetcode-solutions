class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int k=-1;    // initialise the bit by 1 intially and the length of k is the longest....
        for (int i=0;i<n;i++){
            if (nums[i]==i){
                continue;
            }
            else {
                k=(k & nums[i]);   
            }
        }
        if (k==-1){
            return 0;
        }
        return k;
    }
};