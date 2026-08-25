class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        struct bcmp{
            bool operator()(pair<int,int>&a,pair<int,int>&b){
                if (a.first!=b.first){
                    return a.first > b.first;
                }
                return a.second > b.second;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,bcmp>pq;
        unordered_map<int,int> f;
        for (int i=0;i<n;i++){
            f[nums[i]]++;
        }
        for (auto id:f){
            int frequency=id.second;
            int element=id.first;
            pair<int,int> current={frequency,element};
            if (pq.size()<k){
                pq.push(current);
                continue;
            }
            if (pq.top()>=current){
                continue;
            }
            pq.pop();
            pq.push(current);
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

/*

nums = [1,1,2,2,3,3]
k = 2

1 → 2
2 → 2
3 → 2


[1,2] ✅
[1,3] ✅
[2,3] ✅

all valid..
*/