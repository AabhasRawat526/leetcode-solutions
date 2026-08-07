class Solution {
public:

int canmakebouquet(vector<int> & bloomDay,int mid_day , int k){
    int countconsecutive=0;
    int countbouque=0;
    for (int i=0;i<bloomDay.size();i++){
        if (mid_day>=bloomDay[i]){
            countconsecutive++;
        }
        else {
            countconsecutive=0;
        }
        if (countconsecutive==k){
            countbouque++;
            countconsecutive=0;
        }
    }
    return countbouque;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int start_day=0;
        int end_day=*max_element(bloomDay.begin(),bloomDay.end());
        int mindays=-1;
        while(start_day<=end_day){
            int mid_day=start_day+(end_day-start_day)/2;
            if (canmakebouquet(bloomDay,mid_day,k)>=m){
                mindays=mid_day;
                end_day=mid_day-1;
            }
            else {
                start_day=mid_day+1;
            }
        }
        return mindays;
    }
};

// new pattern we are using the binary search in the range not in the give value but in the range that we will make during the left and right one we are applying here too 