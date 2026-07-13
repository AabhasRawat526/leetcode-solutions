class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>f;
        for (int i=0;i<n;i++){
            f[nums[i]]++;
        }
        sort (nums.begin(),nums.end(),[&] (int a,int b){
            if (f[a]!=f[b]){
                return f[a]<f[b];
            }
            return a>b;
        });
        return nums;
    }
};