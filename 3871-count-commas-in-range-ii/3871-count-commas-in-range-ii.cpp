class Solution {
public:
    long long countCommas(long long n) {
        // long long int lower=1000;
        // long long int comma=1;
        // long long int result=0;
        // while(lower<=n){
        //     long long int upper=(lower*1000)-1; 
        //     if(upper>n){
        //         upper=n;
        //     }
        //     long long int countnumber=(upper-lower)+1;
        //     result=result+(countnumber*comma);
        //     lower=lower*1000;
        //     comma++;
        // }
        // return result;

        long long int result=0;
        long long int start=1000;
        while(start<=n){
            result=result+(n-start+1);
            start=start*1000;
        }
        return result;
    }
};