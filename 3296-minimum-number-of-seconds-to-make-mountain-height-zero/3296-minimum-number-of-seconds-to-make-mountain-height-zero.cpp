class Solution {
public:

bool check(vector<int>& workerTimes,int mountainHeight,long long int mid){
    long long int totalheightreduced=0;
    for (int i=0;i<workerTimes.size();i++){
        totalheightreduced=totalheightreduced+sqrt((2*mid/workerTimes[i])+0.25)-0.5;
    }

    if (totalheightreduced>=mountainHeight){
        return true;
    }

    return false;
}

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n=workerTimes.size();
        long long int left=1;
        long long int maxheight=*max_element(workerTimes.begin(),workerTimes.end());
        long long int right=(maxheight)*(mountainHeight)*(mountainHeight+1)/2;
        long long int result=0;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if (check(workerTimes,mountainHeight,mid)){
                result=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return result;
    }
};