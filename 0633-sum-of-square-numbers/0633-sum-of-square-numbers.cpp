class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int i=0;
        long long int j=sqrt(c);
        while(i<=j){
           if ((i*i + j*j) == c){
               return true;
           }
           else if ((i*i + j*j) > c){
               j--;
               if ((i*i + j*j) == c){
                   return true;
               }
           }
           else if ((i*i + j*j) < c){
               i++;
               if ((i*i + j*j) == c){
                   return true;
               }
           }
        }
        return false;
    }
};


/*

equation is a^2+b^2=c^2

let say if the value of a is zero so the value of b will be sqrt(c) this is the part that was needed for the question to be solved ........

*/