class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> res;
        bool add=false;
        for (int i=0;i<n;i++){
            if(add==false and intervals[i][0]>=newInterval[0]){
                add=true;
                res.push_back(newInterval);
            }
            res.push_back(intervals[i]);
        }
        if (n==0){
            res.push_back(newInterval);
        }
        else {
            if (add==false and intervals[n-1][0]<newInterval[0]){
                res.push_back(newInterval);
            }
        }
        vector<vector<int>> merged;
        int len=res.size();
        int start1=res[0][0];
        int end1=res[0][1];
        for (int i=1;i<len;i++){
            int start2=res[i][0];
            int end2=res[i][1];
            if (end1>=start2){
                start1=start1;
                end1=max(end1,end2);
            }
            else {
                merged.push_back({start1,end1});
                start1=start2;
                end1=end2;
            }
        }
        merged.push_back({start1,end1});
        return merged;
    }
};