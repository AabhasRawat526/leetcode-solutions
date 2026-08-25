class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // tc of this solution is 0(nlogn) and sc is 0(n) 
        // during the time of insertion it takes log n times and we are inserting n time so n logn.
        /*
        int n=nums.size();
        set <int> s;
        int j=1;
        for (int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int m=s.size();
        for (auto id:s){
            if ((id)==k*j){
                j++;
            }
        }
        return k*j;
        */
        // tc is 0(n) and sc is 0(n)
        unordered_set<int> f;
        for(int i=0;i<nums.size();i++){
            f.insert(nums[i]);
        }
        int j=1;
        while(f.count(k*j)){
            j++;
        }
        return k*j;
    }
};