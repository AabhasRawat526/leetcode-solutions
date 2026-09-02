class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        for (int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        long long int sum=0;
        while(k--){
            int current1=pq.top();
            pq.pop();
            sum=sum+current1;
            int current2=ceil((current1)/3.0);
            pq.push(current2);
        }
        return sum;
    }
};