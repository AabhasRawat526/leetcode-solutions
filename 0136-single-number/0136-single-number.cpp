class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        int n=nums.size();
        unordered_map<int,int>f;
        for (int i=0;i<n;i++){
            f[nums[i]]++;
        }
        for (auto id: f){
            if (id.second ==1){
                return id.first;
            }
        }
        return {};
        */
        int n=nums.size();
        int result=0;
        for (int i=0;i<n;i++){
            result=(result ^ nums[i]);
        }
        return result;
    }
};