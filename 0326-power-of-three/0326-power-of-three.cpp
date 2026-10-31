class Solution {
public:
    bool isPowerOfThree(int n) {
        /*
        if (n==1){
            return true;
        }
        if(n<=0){
            return false;
        }
        while(n>1){
            if (n%3==0){
                n=n/3;
            }
            else {
                return false;
            }
        }
        return true;
        */
        if (n==1){
            return true;
        }
        if (n<=0){
            return false;
        }
        int x=round(log(n)/log(3));
        if (pow(3,x)==n){
            return true;
        }
        return false;
    }
};