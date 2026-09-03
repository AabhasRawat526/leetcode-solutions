class Solution {
public:

typedef pair<char,int> p;

    string clearStars(string s) {
        int n=s.size();
        struct compare{
            bool operator()(p &p1,p &p2){
                if (p1.first==p2.first){
                    return p1.second<p2.second;
                }
                return p1.first>p2.first;
            }
        };
        priority_queue<p,vector<p>,compare>pq;// min heap
        for (int i=0;i<n;i++){
            if (s[i]!='*'){
                pq.push({s[i],i});
            }
            else {
                int idx=pq.top().second;
                pq.pop();
                s[idx]='*';
            }
        }
        string res;
        for (int i=0;i<n;i++){
            if (s[i]!='*'){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};