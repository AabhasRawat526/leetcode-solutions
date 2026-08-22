class Solution {
public:

bool possible(vector<vector<int>>& matrix,int k,int row,int column,int mid){
    int n=row-1;
    int m=0;
    int count=0;
    while(n>=0 && m<column){
        if (matrix[n][m]<=mid){
            count=count+(n+1);
            m++;
        }
        else {
            n--;
        }
    }
    if (count>=k){
        return true;
    }
    return false;
}


    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int column=matrix[0].size();
        int left=matrix[0][0];
        int right=matrix[row-1][column-1];
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possible(matrix,k,row,column,mid)){
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