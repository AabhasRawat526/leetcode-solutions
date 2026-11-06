class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        int n1=queries.size();
        vector<pair<int,int>> timeresult(n1);
        vector<int> result(n1);
        for (int i=0;i<n1;i++){
            timeresult[i]={queries[i],i};
        }
        sort(timeresult.begin(),timeresult.end());
        auto lambda=[&](vector<int> & vec1,vector<int> & vec2){
            return vec1[1] < vec2[1];
        };
        sort(logs.begin(),logs.end(),lambda);
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        for (auto [time,idx] : timeresult){
            int start=time-x;
            int end=time;
            while(j<m && logs[j][1] <= end){                 // expanding the window
                mp[logs[j][0]]++;
                j++;
            }
            while(i<m && logs[i][1] < start){
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            result[idx] = n-mp.size();         // why n why not m because n is the total number of the server and i need to pass the server with the zero one ....
        }
        return result;
    }
};