class Solution {
public:

double calculatehour(vector<int>& dist,double value){
    double count=0;
    for (int i=0;i<dist.size()-1;i++){
        count=count+ceil(1.0* dist[i]/value);
    }
    count=count+dist[dist.size()-1]/value;
    return count;
}

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1;
        int right=10000000;
        int res=INT_MAX;
        while(left<=right){
            int mid=(left+(right-left)/2);
            double taken=calculatehour(dist,mid);
            if (taken<=hour){
                res=min(res,mid);
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        if (res==INT_MAX){
            return -1;
        }
        return res;
    }
};