class Solution {
public:
/*
bool possible(int mid,int k,int m,int n){
    int count=0;
    int row=m;
    int column=1;
    //int x=row; if u are using x so replace all the rows from the x...
    while(row>=1 && column<=n){ 
        if ((row*column)<=mid){
            count=count+(row);
            column++;
        }
        else {
            row--;
        }
    }
    if (count>=k){
        return true;
    }
    return false;
}

// tc is same 0(m+n)+0(max(m,n)) 

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

*/

bool possible(int mid,int row,int column,int k){
    int count=0;
    int y=1;
    while(row>=1 && y<=column){
        if ((row*y)<=mid){
            count=count+row;
            y++;
        }
        else {
            row--;
        }
    }
    if (count>=k){
        return true;
    }
    return false;
}

    int findKthNumber(int m, int n, int k) {
        int row=m;
        int column=n;
        int left=1;
        int right=m*n;
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possible(mid,row,column,k)){
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