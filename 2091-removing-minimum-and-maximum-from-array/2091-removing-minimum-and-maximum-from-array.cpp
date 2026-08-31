class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return n;
        }
        int maximumIndex=max_element(nums.begin(),nums.end())-nums.begin(); // max element index 
        int minimumIndex=min_element(nums.begin(),nums.end())-nums.begin(); // min element index
        int lefttoright=max(minimumIndex,maximumIndex)+1;
        int righttoleft=n-min(minimumIndex,maximumIndex);
        int leftorright=min(maximumIndex,minimumIndex)+1+n-max(minimumIndex,maximumIndex);
        int deletion=min({lefttoright,righttoleft,leftorright});
        return deletion;
    }
};