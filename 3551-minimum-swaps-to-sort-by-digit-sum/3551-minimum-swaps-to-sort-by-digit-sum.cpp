class Solution {
public:

int getdigitsum(int num){
    int sum=0;
    while(num>0){
        sum=sum+(num%10);
        num=num/10;
    }
    return sum;
}


    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>sortedarray(nums);
        auto lambda=[&](int nums1,int nums2){
            int num1sum=getdigitsum(nums1);
            int num2sum=getdigitsum(nums2);
            if (num1sum!=num2sum){
                return num1sum < num2sum;
            }
            return nums1 < nums2;
        };
        sort(sortedarray.begin(),sortedarray.end(),lambda);

        unordered_map<int,int>f;
        for (int i=0;i<n;i++){
            f[nums[i]]=i;
        }
        int swapcount=0;
        for (int i=0;i<n;i++){
            int currentvalue=nums[i];
            int expectedvalue=sortedarray[i];
            if (currentvalue==expectedvalue){
                continue;
            }
            else {
                int idx=f[expectedvalue];
                nums[i]=expectedvalue;
                nums[idx]=currentvalue;

                f[expectedvalue]=i;
                f[currentvalue]=idx;

                swapcount++;
            }
        }
        return swapcount;
    }
};