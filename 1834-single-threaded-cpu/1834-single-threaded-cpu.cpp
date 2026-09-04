class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>> sortedArray;
        for (int i=0;i<n;i++){
            int start_time=tasks[i][0];
            int process_time=tasks[i][1];
            sortedArray.push_back({start_time,process_time,i});
        }
        sort(sortedArray.begin(),sortedArray.end());
        long long int currenttime=0;
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int idx=0;
        while(idx<n || !pq.empty()){
            if (pq.empty() && currenttime<sortedArray[idx][0]){
                currenttime=sortedArray[idx][0];
            }
            while(idx<n && sortedArray[idx][0]<=currenttime){
                pq.push({sortedArray[idx][1],sortedArray[idx][2]});
                idx++;
            }
            pair<int,int>curr=pq.top();
            pq.pop();
            res.push_back(curr.second);
            currenttime=currenttime+curr.first;
        }
        return res;
    }
};