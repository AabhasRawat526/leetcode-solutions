class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int result=0;
        unordered_set<int>s;
        for (int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        unordered_map<int,int>f;
        while(j<n){
            f[nums[j]]++;
            while(f.size()==s.size()){
                result=result+(n-j);
                f[nums[i]]--;
                if (f[nums[i]]==0){
                    f.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};