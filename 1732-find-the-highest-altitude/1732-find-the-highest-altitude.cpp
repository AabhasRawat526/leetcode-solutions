class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>res(n+1);
        res[0]=0;
        for (int i=1;i<n+1;i++){
            res[i]=res[i-1]+gain[i-1];
        }
        int maxaltitude=INT_MIN;
        for (int i=0;i<n+1;i++){
            maxaltitude=max(maxaltitude,res[i]);
        }
        return maxaltitude;
    }
};