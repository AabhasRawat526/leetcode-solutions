class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int,vector<int>,greater<int>> pq2;
        int hired=0;
        int i=0;
        int j=n-1;
        long long int answer=0;
        while(hired<k){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<candidates && j>=i){
                pq2.push(costs[j]);
                j--;
            }
            int minimumvaluep1=pq1.size()>0 ? pq1.top() : INT_MAX;
            int minimumvaluep2=pq2.size()>0 ? pq2.top() : INT_MAX;
            if(minimumvaluep1<=minimumvaluep2){
                answer=answer+minimumvaluep1;
                pq1.pop();
            }
            else {
                answer=answer+minimumvaluep2;
                pq2.pop();
            }
            hired++;
        }
        return answer;
    }
};