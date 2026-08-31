class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>pq; // default max heap;
        for (int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        while(k--){
            int current=pq.top();
            pq.pop();
            int division=(current+1)/2;
            pq.push(division);
        }
        int sum=0;
        while(!pq.empty()){
            sum=sum+pq.top();
            pq.pop();
        }
        return sum;
    }
};