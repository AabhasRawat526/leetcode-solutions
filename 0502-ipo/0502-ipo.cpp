class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>> project;
        for(int i=0;i<n;i++){
            project.push_back({capital[i],profits[i]});
        }
        sort(project.begin(),project.end());
        int idx=0;
        int res=0;
        priority_queue<int> pq;
        while(k--){
            while(idx<n){
                if (project[idx].first>w){
                    break;
                }
                pq.push(project[idx].second);
                idx++;
            }
            if (pq.empty()){
                return w;
            }
            w=w+pq.top();
            res=w;
            pq.pop();
        }
        return res;
    }
};