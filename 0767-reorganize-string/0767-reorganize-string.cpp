class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        string res="";
        unordered_map<char,int> f;
        for (int i=0;i<n;i++){
            f[s[i]]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        for(auto id:f){
            pq.push({id.second,id.first});
        }
        int seat=0;
        while(!pq.empty()){
            pair<int,char> current={pq.top().first,pq.top().second};
            if(seat==0 || res[seat-1]!=current.second){
                res.push_back(current.second);
                pq.pop();
                current.first--;
                seat++;
                if (current.first >0){
                    pq.push(current);
                }
            }
            else {
                pair<int,char> current3={pq.top().first,pq.top().second};
                pq.pop();
                if (pq.empty()){
                    return "";
                }
                pair<int,char> current2={pq.top().first,pq.top().second};
                //pq.pop();
                res.push_back(current2.second);
                pq.pop();
                seat++;
                current2.first--;
                if (current2.first>0){
                    pq.push(current2);
                }
                pq.push(current3);
            }
        }
        if (res.size()!=s.size()){
            return "";
        }
        return res;
    }
};