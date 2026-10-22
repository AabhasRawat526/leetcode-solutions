class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ascendingcount=0;
        int descendingcount=0;
        for (int i=1;i<n;i++){
            ascendingcount+=(nums[i]==(nums[i-1]+1)%n);
            descendingcount+=(nums[i-1]==(nums[i]+1)%n);
        }
        if (ascendingcount==n-1 && nums[0]==0){
            return 0;
        }
        if (ascendingcount==n-1){
            int leftshift=n-nums[0];
            int rightshif=1+(nums.back()+1) + 1;
            return min(leftshift,rightshif);
        }
        if (descendingcount==n-1){
            int leftshiftcount=n-nums.back()+1; // because 1 times we are doing mandatory reverse so that we can convert the descending array into the ascending array
            int rightshiftcount=(nums[0]+1)%n+ 1;  // +1 for the reverse
            return min(leftshiftcount,rightshiftcount);
        }
        return -1;
    }
};