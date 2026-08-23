class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for (int i=0;i<n;i++){
            s.insert(nums[i]);
            if (s.size()>3){
                s.erase(s.begin());
            }
        }
        if (s.size()<3){
            return *prev(s.end());
        }
        return *(s.begin());
    }
};