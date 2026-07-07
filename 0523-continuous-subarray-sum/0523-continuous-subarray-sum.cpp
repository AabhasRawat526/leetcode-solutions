class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> f;
        f[0]=-1;
        int sum=0;
        for (int i=0;i<n;i++){
            sum=sum+nums[i];
            int remainder=(sum%k);
            if (f.find(remainder)!=f.end()){    // kyu wo remainder phele aaya hai 
                if (i-f[remainder]>=2){
                    return true;
                }
            }
            else {
                f[remainder]=i;
            }
        }
        return false;
    }
};