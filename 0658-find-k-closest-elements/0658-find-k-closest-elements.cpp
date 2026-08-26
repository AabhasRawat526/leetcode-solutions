class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq; // max heap;
        for (int i=0;i<n;i++){
            int difference=abs(arr[i]-x);
            pair<int,int>current={difference,arr[i]};
            if (pq.size()<k){
                pq.push(current);
                continue;
            }
            if (pq.top()<=current){  // max heap <=
                continue;
            }
            else {
                pq.pop();
                pq.push(current);
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// can be done with the help of binary solution will solve next time 