class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int result=0;
        int maxelement=*max_element(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        int countmaxelement=0;
        while(j<n){
            if(nums[j]==maxelement){
                countmaxelement++;
            }
            while(countmaxelement >= k){
                result=result+n-j;
                if (nums[i]==maxelement){
                    countmaxelement--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};