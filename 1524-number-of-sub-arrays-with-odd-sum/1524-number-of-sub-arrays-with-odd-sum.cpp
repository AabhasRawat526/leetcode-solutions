class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int M=1e9+7;
        int n=arr.size();
        int sum=0;
        int evencount=1;
        int oddcount=0;
        int count=0;
        for (int i=0;i<n;i++){
            sum=sum+arr[i];
            if (sum%2==0){          // even + odd = odd 
                count=(count+oddcount)%M;
                evencount++;
            }
            else {                  // odd + even = odd
                count=(count+evencount)%M;
                oddcount++;
            }
        }
        return count;
    }
};