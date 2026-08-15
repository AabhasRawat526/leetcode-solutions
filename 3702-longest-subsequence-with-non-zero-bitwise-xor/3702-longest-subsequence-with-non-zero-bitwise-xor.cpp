class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        bool allzero=true;

        for (int x:nums){
            if (x!=0){
                allzero=false;
            }
            result=(result^x);
        }
        if (allzero==true){
            return 0;
        }  
        if (result==0){
            return n-1;
        }    
        return n;
    }
};