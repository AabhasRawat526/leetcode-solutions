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


/*

Step 1:
Put mid at index.

Step 2:
Keep decreasing by 1 while possible.

Step 3:
If you reach 1 before reaching the boundary,
fill the remaining cells with 1.

Step 4:
Do the same on the right.

Step 5:
Compute the total sum.

If total ≤ maxSum,
this height is possible.
Otherwise,
it's impossible.


*/