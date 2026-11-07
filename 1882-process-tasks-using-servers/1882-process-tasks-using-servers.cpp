class Solution {
public:

typedef pair<int,int> P;
typedef tuple<long long int, int ,int> T;

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<P , vector<P> , greater<P>> freeserver;
        priority_queue<T, vector<T>, greater<T>> busyserver;
        vector<int> result(m);
        for (int i=0;i<n;i++){
            freeserver.push({servers[i],i});
        }
        for (int i=0;i<m;i++){
            while(!busyserver.empty() && get<0>(busyserver.top())<=i){
                auto[finishtime,weight,idx] = busyserver.top();
                freeserver.push({weight,idx});
                busyserver.pop();
            }
            if (freeserver.empty()){
                auto[finishtime,weight,idx] = busyserver.top();
                busyserver.pop();
                result[i]=idx;
                busyserver.push({finishtime + tasks[i],weight,idx});
            }
            else {
                auto [weight,idx] = freeserver.top();
                freeserver.pop();
                result[i]=idx;
                busyserver.push({i+tasks[i] , weight,idx});
            }
        }
        return result;
    }
};