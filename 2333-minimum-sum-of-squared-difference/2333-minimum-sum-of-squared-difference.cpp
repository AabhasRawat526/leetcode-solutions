class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>resultant(1e5+1,0);
        int k=k1+k2;
        int n=nums1.size();
        for (int i=0;i<n;i++){
            int difference=abs(nums1[i]-nums2[i]);
            resultant[difference]++;
        }
        for (int i=1e5;i>0;i-- && k>0){
            int currentcount=min(resultant[i],k);
            resultant[i]=resultant[i]-currentcount;
            resultant[i-1]=resultant[i-1]+currentcount;
            k=k-currentcount;
        }
        long long int result=0;
        for (int i=0;i<1e5+1;i++){
            result+=1LL * resultant[i]*i*i;
        }
        return result;
    }
};