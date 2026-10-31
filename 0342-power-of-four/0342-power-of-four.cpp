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
    }
};