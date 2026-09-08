class Solution {
public:
    int countCommas(int n) {
        // int m=(n/1000);
        // int count=0;
        // if (m==0){
        //     return 0;
        // }
        // for (int num=1000;num<=n;num++){
        //     count=count+1;
        // }
        // return count;
        int count;
        if(n<1000){
            return 0;
        }
        else {
            int num=n-999;
            count=num;
        }
        return count;
    }
};