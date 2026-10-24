class Solution {
public:

int findtotaldays (string months,int totaldays[]){
    int month=stoi(months.substr(0,2));
    int day = stoi(months.substr(3));
    return totaldays[month-1] + day;
}

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
       vector<int>days={31,28,31,30,31,30,31,31,30,31,30,31};
       vector<int>totalmonths(13,0);
       int totaldays[13]={0};
       for (int i=1;i<13;i++){
            totaldays[i]=totaldays[i-1]+days[i-1];
        }
        int arriveAliceDay = findtotaldays(arriveAlice,totaldays);
        int leaveAliceDay = findtotaldays(leaveAlice,totaldays);
        int arriveBobDay = findtotaldays(arriveBob,totaldays);
        int leaveBobDay = findtotaldays(leaveBob,totaldays);
        int overlapdays = min(leaveBobDay,leaveAliceDay) - max(arriveAliceDay,arriveBobDay) + 1;

        return overlapdays < 0 ? 0 : overlapdays;
    }
};