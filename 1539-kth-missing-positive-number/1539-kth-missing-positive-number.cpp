class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        /*

        by using linear search 

        int n=arr.size();
        int num=1;
        int i=0;
        while(i<n && k>0){
            if (arr[i]==num){
                i++;
            }
            else {
                k--;
            }
            num++;
        }

        while(k--){
            num=num+1;
        }
        return num-1;

        */

        // with the help of binary search we can solve this question too and here is how we are solving

        int n=arr.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            int missingelement=arr[mid]-(mid+1);
            if (missingelement<k){
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        return left+k;
    }
};