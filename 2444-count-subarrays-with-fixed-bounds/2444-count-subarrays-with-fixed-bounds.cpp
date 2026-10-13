class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minkposition=-1;
        int maxkposition=-1;
        int culpritindexposition=-1;
        int n=nums.size();
        long long int answer=0;
        for (int i=0;i<n;i++){
            if (nums[i]<minK || nums[i]>maxK){
                culpritindexposition=i;
            }
            if (nums[i]==minK){
                minkposition=i;
            }
            if (nums[i]==maxK){
                maxkposition=i;
            }
            long long int smaller=min(minkposition,maxkposition);
            long long int temp=smaller-culpritindexposition;
            answer+=(temp<=0) ? 0 : temp;
        }
        return answer;
    }
};