class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<array<int,3>>sortedArray;
        for (int i=0;i<n;i++){
            int starttime=tasks[i][0];
            int processtime=tasks[i][1];
            sortedArray.push_back({starttime,processtime,i});
        }
        sort(sortedArray.begin(),sortedArray.end());
        vector<int>res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq; // Then it automatically sorts/orders the elements you push into the priority queue in ascending order.
        long long int currenttime=0;
        int idx=0;
        while(idx<n || !pq.empty()){
            if (pq.empty() && currenttime<sortedArray[idx][0]){
                currenttime=sortedArray[idx][0];
            }
            while(idx<n && currenttime>=sortedArray[idx][0]){
                pq.push({sortedArray[idx][1],sortedArray[idx][2]});
                idx++;
            }
            pair<int,int>curr=pq.top();
            pq.pop();
            currenttime=currenttime+curr.first;
            res.push_back(curr.second);
        }
        return res;
    }
};