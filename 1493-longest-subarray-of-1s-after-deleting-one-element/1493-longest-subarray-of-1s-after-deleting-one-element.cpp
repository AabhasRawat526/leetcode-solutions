class Solution {
public:
// Brute force so that is why tle 
/*
int n;
int findmax(vector<int>& nums,int skipidx){
    int currentlength=0;
    int maxlength=0;
    for (int i=0;i<n;i++){
        if (i==skipidx){
            continue;
        }
        if (nums[i]==1){
            currentlength++;
            maxlength=max(maxlength,currentlength);
        }
        else {
            currentlength=0;
        }
    }
    return maxlength;
}

    int longestSubarray(vector<int>& nums) {
        n=nums.size();
        int countzero=0;
        int result=0;
        for (int i=0;i<n;i++){
            if (nums[i]==0){
                countzero++;
                result=max(result,findmax(nums,i));
            }
        }
        if (countzero==0){
            return n-1;
        }
        return result;
        */

    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxlength=0;
        int j=0;
        int i=0;
        int countzero=0;
        while(j<n){
            if (nums[j]==0){
                countzero++;
            }
            while(countzero>1){
                if (nums[i]==0){
                    countzero--;
                }
                i++;
            }
            maxlength=max(maxlength,j-i);
            j++;
        }
        return maxlength;
    }
};