class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> pq; // default max heap 
        for (int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int current1=pq.top();
            pq.pop();
            int current2=pq.top();
            pq.pop();
            if(current1==current2){
                pq.push(0);
            }
            else {
                int difference=abs(current1-current2);
                pq.push(difference);
            }
        }
        return pq.top();
    }
};