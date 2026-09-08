class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<vector<int>> res;
        for (int i=0;i<n;i++){
            res.push_back({nums1[i],i,nums2[i]});
        }

        sort(res.begin(),res.end());
        long long int result=0;
        priority_queue<int,vector<int>,greater<>>pq;
        vector<long long>answer(n);
        for (int i=0;i<n;i++){
            if (i>0 and res[i-1][0]==res[i][0]){
                answer[res[i][1]]=answer[res[i-1][1]];
            }
            else {
                answer[res[i][1]]=result;
            }
            pq.push(res[i][2]);
            result=result+res[i][2];
            if (pq.size()>k){
                result=result-pq.top();
                pq.pop();
            }

        }
        return answer;
    }
};