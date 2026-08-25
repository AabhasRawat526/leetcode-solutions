class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        if (points.size()==0){
            return res;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq; // max heap me nahi banayenge bcmp wala and all structure...
        int n=points.size();
        for (int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int distance=(x*x+y*y);    // working in double can if i use int it will only take the value which is before the point and if i want whole answer i will choose double or we can still pass int and int one will work by removing the sqrt one 
            pair<int,int>current={distance,i};
            if (pq.size()<k){
                pq.push(current);
                continue;
            }
            if (pq.top()<=current){  // max heap me <= and min heap me >=
                continue;
            }
            else {
                pq.pop();
                pq.push(current);
            }
        }
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};