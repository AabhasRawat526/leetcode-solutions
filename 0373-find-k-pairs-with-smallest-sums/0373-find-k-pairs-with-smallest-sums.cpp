class Solution {
public:

typedef pair<int,pair<int,int>> p;
// typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        //brute force code 


        // priority_queue<p,vector<p>> pq;
        // int n=nums1.size();
        // int m=nums2.size();
        // for (int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int sum=nums1[i]+nums2[j];
        //         if(pq.size()<k){
        //             pq.push({sum,{i,j}});
        //         }
        //         else if (pq.top().first > sum){
        //             pq.pop();
        //             pq.push({sum,{i,j}});
        //         }
        //         else {
        //             break;
        //         }
        //     }
        // }
        // vector<vector<int>> res;
        // while(!pq.empty()){
        //     int i=pq.top().second.first;
        //     int j=pq.top().second.second;
        //     res.push_back({nums1[i],nums2[j]});
        //     pq.pop();
            
        // }
        // return res;
        

        // optimum solution 

        int n=nums1.size();
        int m=nums2.size();

        priority_queue<p,vector<p>,greater<p>> pq;  // min heap to get the minimum value ...

        int sum=nums1[0]+nums2[0];

        pq.push({sum,{0,0}});

        set<pair<int,int>> s;
        s.insert({0,0});

        vector<vector<int>> res;

        while(k-- and !pq.empty()){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            res.push_back({nums1[i],nums2[j]});
            pq.pop();

            // to check for the i+1 and j+1 condition can we insert the i+1 and j+1 is yes then go and if no so leave the loop 
            // here checking for the j+1 

            if (j+1<m and s.find({i,j+1})==s.end()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
            // now for i+1 
            if (i+1<n and s.find({i+1,j})==s.end()){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                s.insert({i+1,j});
            }
        }
        return res;
    }
};