class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long int peaks=n/2;
        long long jumps=peaks-1;
        if (n==1){
            return s;
        }
        long long int firstpeak=s+m;
        long long int maximum=firstpeak+jumps*(m-1);
        return maximum;
    }
};