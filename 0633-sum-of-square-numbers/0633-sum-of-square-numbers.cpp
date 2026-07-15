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