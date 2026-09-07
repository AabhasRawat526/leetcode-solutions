class Solution {
public:

typedef pair<int,int> p;

    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<p,vector<p>,greater<p>> pq;  // min heap of pairs
        vector<int> temp(n,false);
        for (int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long int score=0;
        while(!pq.empty()){
            auto result=pq.top();
            int element=result.first;
            int idx=result.second;
            pq.pop();
            if (temp[idx]==false){
                temp[idx]=true;
                score=score+element;
                if (idx-1>=0 && temp[idx-1]==false){
                    temp[idx-1]=true;
                }
                if (idx+1<n && temp[idx+1]==false){
                    temp[idx+1]=true;
                }
            }
        }
        return score;
    }
};