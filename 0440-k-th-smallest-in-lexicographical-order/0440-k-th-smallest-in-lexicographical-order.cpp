class Solution {
public:

int Count(long long current,long long next,int n){
    int currentcount=0;
    while(current<=n){
        currentcount=currentcount+(next-current);
        current=current*10;
        next=next*10;
        next=min(next,(long long)(n+1));
    }
    return currentcount;
}

    int findKthNumber(int n, int k) {
        int current=1;
        k=k-1;
        while(k>0){
            int count=Count(current,current+1,n);
            if (count<=k){
                current=current+1;
                k=k-count;
            }
            else {
                current=current*10;
                k=k-1;
            }
        }
        return current;
    }
};