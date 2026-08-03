class Solution {
public:


long long int getsum(long long count,int x){    // here count is the mid sum and the x is the index

    return (count*x)-(count*(count+1)/2);

}

    int maxValue(int n, int index, int maxSum) {
        int left=1;
        int right=maxSum;

        int result=0;

        while(left<=right){
            long long int mid=(left+right)/2;
            long long leftcount= min((long long int)index,mid-1);
            long long leftsum=getsum(leftcount,mid);
            leftsum=leftsum+max(0ll,index-(mid-1));  // extra one if there so we are adding it 

            long long rightcount=min((long long int)n-index-1,mid-1);
            long long rightsum=getsum(rightcount,mid);
            rightsum=rightsum+max(0ll,n-index-1-(mid-1));  // same extra one is there is so we are adding

            long long int totalsum=leftsum+mid+rightsum;

            if (totalsum<=maxSum){
                result=max((long long int)result,mid);
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        return result;
    }
};