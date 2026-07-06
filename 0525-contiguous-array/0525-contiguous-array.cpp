class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        unordered_map<int,int> f;
        int res=0;
        for (int i=0;i<n;i++){
            if (nums[i]==0){
                zero++;
            }
            else {
                one++;
            }
            int difference=zero-one;
            if (difference==0){
                res=max(res,i+1);
            }
            if (f.find(difference)==f.end()){
                f[difference]=i;
            }
            else {
                int idx=f[difference];
                int length=i-idx;
                res=max(res,length);
            }
        }
        return res;
    }
};