class Solution {
public:
    bool isPowerOfFour(int n) {
        // kind of ugly number logic is same as the ugly number .....
        // approach 1 
        /*
        if(n==1){
            return true;
        }
        if (n<=0){
            return false;
        }
        while(n>1){
            if (n%4==0){
                n=n/4;
            }
            else {
                return false;
            }
        }
        return true;
        */
        /*
        if (n==1){
            return true;
        }
        if (n<=0){
            return false;
        }
        int x=log(n)/log(4);

        if (pow(4,x)==n){
            return true;
        }
        return false;
        */
        if (n==1){
            return true;
        }
        if (n<=0){
            return false;
        }
        if ((n & (n-1))== 0 && (n-1)%3 == 0) {
            return true;
        }
        return false;
    }
};