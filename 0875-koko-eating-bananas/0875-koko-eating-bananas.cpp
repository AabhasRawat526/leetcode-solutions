class Solution {
public:
long long int function(vector<int>& a,int speed){
    long long int hour=0;
    for(int i=0;i<a.size();i++){
        hour=hour+a[i]/speed;
        if (a[i]%speed!=0){
            hour++;
        }
    }
    return hour;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int n=piles.size();
        int maximum=INT_MIN;
        for (int i=0;i<n;i++){
            maximum=max(maximum,piles[i]);
        }
        int high=maximum;
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            long long int hour = function(piles,guess);
            if (hour>h){
                low=guess+1;
            }
            else {
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};