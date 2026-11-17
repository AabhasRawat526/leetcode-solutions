class Solution {
public:
    long long coloredCells(int n) {
        /*
        tc is 0(n)
        long long int cell=1;
        long long int t=1;
        while(t<=n){
            cell=cell+4*(t-1);
            t++;
        }
        return cell;
        */

        long long int cellcovered= 1LL + 2LL * (n) * (n-1);
        return cellcovered;
    }
};