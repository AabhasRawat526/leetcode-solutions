class Solution {
public:

int M=1e9+7;
        int findPower(long long int a,long long int b){
            if (b==0){
                return 1;
            }
            long long int half=findPower(a,b/2);
            long long int result=(half*half) % M;
            if (b%2==1){
                return (result*a) % M;
            }
            return result;
        }
    int countGoodNumbers(long long n) {
        return (long long) findPower(5,(n+1)/2) * findPower(4,n/2) % M;
    }
};