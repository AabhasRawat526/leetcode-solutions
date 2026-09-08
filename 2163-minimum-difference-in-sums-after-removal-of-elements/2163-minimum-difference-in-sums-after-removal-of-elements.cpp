class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
       int n=nums.size();
       int N=(n/3);
       priority_queue<int>max_heap;
       priority_queue<int,vector<int>,greater<int>>min_heap;
       vector<long long int> leftSum(n,0);
       vector<long long int> rightSum(n,0);
       long long int leftsum=0;
       for (int i=0;i<2*N;i++){
            max_heap.push(nums[i]);
            leftsum=leftsum+nums[i];
            if (max_heap.size()>N){
                leftsum=leftsum-max_heap.top();
                max_heap.pop();
            }
            leftSum[i]=leftsum;
       }
       long long int rightsum=0;
       for (int i=n-1;i>=0;i--){
            min_heap.push(nums[i]);
            rightsum=rightsum+nums[i];


            if (min_heap.size()>N){
                rightsum=rightsum-min_heap.top();
                min_heap.pop();
            }
            rightSum[i]=rightsum;
       }
       long long int result = LLONG_MAX;
       for (int i=N-1;i<=2*N-1;i++){
            result=min(result,leftSum[i]-rightSum[i+1]);
       }
       return result;
    }
};