class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector <int> missing;
        sort(nums.begin(),nums.end());
        int minnumber=*min_element(nums.begin(),nums.end());
        int i=0;
        int maxnumber=*max_element(nums.begin(),nums.end());
        while(minnumber<=maxnumber){
            if (minnumber==nums[i]){
                i++;
                minnumber++;
            }
            else {
                missing.push_back(minnumber);
                minnumber++;
            }
        }
        return missing;
    }
};