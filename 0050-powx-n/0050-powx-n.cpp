class Solution {
public:

double solve(long double x,long long int n){
    if (n==0){
        return 1;
    }
    if (n<0){
        return solve(1/x,-n);
    }
    if (n%2==0){
        return solve(x*x,n/2);
    }
    return x * solve(x*x,(n-1)/2);
}

    double myPow(double x, int n) {
        // return pow(x,n); not going to be accepted in interview because i am using a built in function so that is why it will not be accptable in the intrview 
        // using recursion

        return solve((long double) x,(long long) n);
    }
};