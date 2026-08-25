class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        struct bcmp{
            bool operator()(pair<int,string>&a,pair<int,string>&b){
                if (a.first!=b.first){
                    return a.first>b.first;
                }
                return a.second<b.second;
            }
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,bcmp>pq;
        unordered_map<string,int>f;
        for (int i=0;i<n;i++){
            f[words[i]]++;
        }
        for (auto id:f){
            string word=id.first;  // frequency ke basic pe hoga sab sort
            int frequency=id.second;
            pair<int,string> current={frequency,word};
            if (pq.size()<k){
                pq.push(current);
                continue;
            }
            if (pq.top().first>current.first || pq.top().first==current.first && pq.top().second<current.second){
                continue;
            }
            else {
                pq.pop();
                pq.push(current);
            }
        }
        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

/*

Short summary
pair<int,string> → {frequency, word}
pq.top() = worst among current K

Different frequency:

return a.first > b.first;

→ smaller frequency comes on top

Same frequency:

return a.second < b.second;

→ alphabetically larger word comes on top

Why? So we can easily remove the worst when a better word appears.
Don't use pq.top() >= current because it uses normal pair comparison, not your custom comparator.

*/