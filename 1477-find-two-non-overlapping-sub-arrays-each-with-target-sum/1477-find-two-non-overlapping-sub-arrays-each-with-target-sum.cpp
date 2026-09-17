class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        vector<int>bestindextillnow(n,INT_MAX);
        int result=INT_MAX;
        int bestminlength=INT_MAX;
        int currentsum=0;
        while(j<n){
            currentsum=currentsum+arr[j];
            while(i<j && currentsum>target){
                currentsum=currentsum-arr[i];
                i++;
            }
            if (currentsum==target){
                int length=j-i+1;
                if (i>0 && bestindextillnow[i-1]!=INT_MAX){
                    result=min(result,bestindextillnow[i-1]+length);
                }
                bestminlength=min(bestminlength,length);
            }
            bestindextillnow[j]=bestminlength;
            j++;
        }
        return result==INT_MAX ? -1 : result;
    }
};