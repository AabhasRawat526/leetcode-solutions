class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> res;
        for (int i=0;i<n;i++){
            res.push_back({nums1[i],nums2[i]});
        }

        auto lambda=[&](auto &p1,auto &p2){
            return p1.second>p2.second;
        };

        sort(res.begin(),res.end(),lambda);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long int kSum=0;
        for (int i=0;i<=k-1;i++){
            kSum=kSum+res[i].first;
            pq.push(res[i].first);
        }
        long long int result=kSum*res[k-1].second;
        for (int i=k;i<n;i++){
            kSum=kSum+res[i].first-pq.top();
            pq.pop();
            pq.push(res[i].first);
            long long int res2=kSum*res[i].second;
            result=max(result,res2);
        }
        return result;
    }
};