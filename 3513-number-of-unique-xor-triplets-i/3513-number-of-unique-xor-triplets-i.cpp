class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if (n==1 || n==2){
            return n;
        }
        int result=0;
        for (int i=0;i<n;i++){
            result=pow(2,i);
            if (n<result){
                return result;
            }
        }
        return {};
    }
};