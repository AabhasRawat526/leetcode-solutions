class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){   // tc is 0(n)
            res.push_back({nums1[i],i,nums2[i]});
        }
        sort(res.begin(),res.end());  // tc is 0(n logn)
        priority_queue<int,vector<int>,greater<int>>pq;
        long long int sum=0;
        vector<long long> ans(n);
        for (int i=0;i<n;i++){  // tc is 0(n) and because of push and pop there will be tc 0(n logk)
            if (i>0 and res[i-1][0]==res[i][0]){
                ans[res[i][1]]=ans[res[i-1][1]];
            }
            else {
                ans[res[i][1]]=sum;
            }
            pq.push(res[i][2]);
            sum=sum+res[i][2];
            if (pq.size()>k){
                sum=sum-pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};