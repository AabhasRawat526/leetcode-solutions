class Solution {
public:
    long long coloredCells(int n) {
        long long int cell=1;
        long long int t=1;
        while(t<=n){
            cell=cell+4*(t-1);
            t++;
        }
        return cell;
    }
};