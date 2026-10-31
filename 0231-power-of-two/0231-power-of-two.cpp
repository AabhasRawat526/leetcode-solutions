class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*
        if (n==1){
            return true;
        }
        if (n<=0){
            return false;
        }
        while(n>1){
            if (n%2==0){
                n=n/2;
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
        int x=log(n)/log(2);
        if (pow(2,x)==n){
            return true;
        }
        return false;
    }
};