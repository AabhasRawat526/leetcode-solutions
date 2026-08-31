class Solution {
public:
    string frequencySort(string s) {
        struct lambda{
            bool operator()(pair<char,int>&p1,pair<char,int>&p2){
                return p1.second<p2.second;
            }
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,lambda>pq;
        unordered_map<char,int>f;
        int n=s.size();
        for (int i=0;i<n;i++){
            f[s[i]]++;
        }
        for (auto id:f){
            char words=id.first;
            int frequency=id.second;
            pair<char,int> current={words,frequency};
            pq.push(current);
        }
        string res;
        while(!pq.empty()){
            pair<char,int> temp=pq.top();
            pq.pop();
            res=res+string(temp.second,temp.first);  //creates a string containing that character repeated that many times.
        }
        return res;
    }
};