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
            if (res.size()>=2 && res[res.size()-1]==currentword && res[res.size()-2] == currentword){
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

// tc is 0(n) because outer loop is occuring n times and push pop we are doing for the 3 times which is constant so tc is 0(n) 

// sc is 0(n) because of string res;