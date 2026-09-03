class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        string res="";
        if (a>0){
            pq.push({a,'a'});
        }
        if (b>0){
            pq.push({b,'b'});
        }
        if (c>0){
            pq.push({c,'c'});
        }
        while(!pq.empty()){
            int currentfrequency=pq.top().first;
            char currentword=pq.top().second;
            pq.pop();
            if (res.length()>=2 && res[res.length()-1]==currentword && res[res.length()-2] == currentword){
                if (pq.empty()){
                    break;
                }
                int nextfrequency=pq.top().first;
                char nextword=pq.top().second;
                pq.pop();
                res.push_back(nextword);
                nextfrequency--;
                if (nextfrequency>0){
                    pq.push({nextfrequency,nextword});
                }
                pq.push({currentfrequency,currentword});
            }
            else {
                res.push_back(currentword);
                currentfrequency--;
                if (currentfrequency>0){
                    pq.push({currentfrequency,currentword});
                }
            }
        }
        return res;
    }
};