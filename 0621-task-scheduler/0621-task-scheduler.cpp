class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>index(26,0);
        for(char &ch:tasks){
            index[ch-'A']++;
        }

        priority_queue<int> pq;
        for (int &frequency:index){
            if (frequency>0){
                pq.push(frequency);
            }
        }
        int time=0;
        while(!pq.empty()){
            vector<int> res;
            for (int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int current=pq.top();
                    pq.pop();
                    current--;
                    res.push_back(current);
                }
            }
            for (int &count:res){
                if (count>0){
                    pq.push(count);
                }
            }
            if (pq.empty()){
                time=time+res.size();
            }
            else {
                time=time+n+1;
            }
        }
        return time;
    }
};