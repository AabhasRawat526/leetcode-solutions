class Solution {
public:

typedef pair<int,int>P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>availableserver;
        priority_queue<P,vector<P>,greater<P>>busyserver;
        vector<int>result(k,0);
        for (int i=0;i<k;i++){
            availableserver.insert(i);
        }
        for (int i=0;i<arrival.size();i++){
            while(!busyserver.empty() && busyserver.top().first <= arrival[i]){
                auto [finishtime,serverid]=busyserver.top();
                busyserver.pop();
                availableserver.insert(serverid);
            }
            int target=i%k;
            auto it = availableserver.lower_bound(target);     // it is the iterator 
            if (it == availableserver.end()){     // wrap around logic 
                it = availableserver.begin();
            }
            if (availableserver.empty()){
                continue;
            }
            int targetserver=*it;
            availableserver.erase(it);
            busyserver.push({arrival[i]+load[i],targetserver});
            result[targetserver]++;
        }
        int maxvalue=*max_element(result.begin(),result.end());
        vector<int>maxivalue;
        for (int i=0;i<result.size();i++){
            if (result[i]==maxvalue){
                maxivalue.push_back(i);
            }
        }
        return maxivalue;
    }
};