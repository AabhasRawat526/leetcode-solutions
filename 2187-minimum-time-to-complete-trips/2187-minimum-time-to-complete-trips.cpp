class Solution {
public:

bool possible(vector<int>&time,long long int giventime,int totalTrips){
    long long int actualtime=0;
    for (int i=0;i<time.size();i++){
        actualtime=actualtime+(giventime/time[i]);
    }
    return actualtime>=totalTrips;
}

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int n=time.size();
        long long int left=1;
        long long int right=(long long)(*min_element(time.begin(),time.end()))*totalTrips;

        while(left<right){
            long long int mid=(left+right)/2;
            if (possible(time,mid,totalTrips)){
                right=mid;
            }
            else {
                left=mid+1;
            }
        }
        return left;
    }
};