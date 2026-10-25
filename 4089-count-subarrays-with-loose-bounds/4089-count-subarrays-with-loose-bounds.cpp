class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int lastinvalidindex=-1;
        long long int answer=0;
        for (int j=0;j<n;j++){
            if (nums[j] < minK || nums[j] > maxK){
                lastinvalidindex=j;
            }
            answer=answer+j-lastinvalidindex;
        }
        return answer;
    }
};