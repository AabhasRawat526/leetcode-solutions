class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
        for (int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        long long int count=0;
        while(pq.top()<k){
            long long int min1=pq.top();
            pq.pop();
            long long int min2=pq.top();
            pq.pop();
            long long int ans=min(min1,min2)*2+max(min1,min2);
            pq.push(ans);
            count++;
        }
        return count;
    }
};