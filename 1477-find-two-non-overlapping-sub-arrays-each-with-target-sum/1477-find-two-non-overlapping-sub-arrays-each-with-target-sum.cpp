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
                //  // Is there a valid subarray BEFORE me?
                if (i>0 && bestindextillnow[i-1]!=INT_MAX){
                    //  // Combine them
                    result=min(result,bestindextillnow[i-1]+length); // to handle the overlap we do this part 
                }
                // Remember current subarray if it is the shortest
                bestminlength=min(bestminlength,length);
            }
            // Save shortest valid subarray up to j
            bestindextillnow[j]=bestminlength;
            j++;
        }
        return result==INT_MAX ? -1 : result;
    }
};