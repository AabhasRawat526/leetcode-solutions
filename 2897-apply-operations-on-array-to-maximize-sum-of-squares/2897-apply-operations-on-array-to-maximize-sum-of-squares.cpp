class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD=1e9+7;
        vector<int> count(32,0);
        for (int & num : nums){
            for (int b=0;b<32;b++){
                if (num & (1<<b)){
                    count[b]++;
                }
            }
        }
        long long int result=0;
        while(k--){
            long long int current=0;
            for (int b=0;b<32;b++){
                if (count[b]>0){
                    count[b]--;
                    current=(current | (1<<b));
                }
            }
            result=(result+(current*current))%MOD;
        }
        return result;
    }
};