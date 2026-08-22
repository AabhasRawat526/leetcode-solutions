class Solution {
public:

bool possible(int mid,int k,int m,int n){
    int count=0;
    int row=m;
    int column=1;
    int x=row;
    while(x>=1 && column<=n){
        if ((x*column)<=mid){
            count=count+(x);
            column++;
        }
        else {
            x--;
        }
    }
    if (count>=k){
        return true;
    }
    return false;
}

    int findKthNumber(int m, int n, int k) {
        int left=1;
        int right=m*n;
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if (possible(mid,k,m,n)){
                res=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return res;
    }
};