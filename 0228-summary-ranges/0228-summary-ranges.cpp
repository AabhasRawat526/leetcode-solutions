class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector <string> res;
        for (int i=0;i<n;i++){
            int start=nums[i];
            int end=nums[i];

            while(i+1<n && nums[i+1] == nums[i]+1){
                i++;
                end=nums[i];
            }
            string ans=to_string(start)+"->"+ to_string(end);
            if (start==end){
                ans=to_string(start);     /// overwriting ...
            }
            res.push_back(ans);
        }
        return res;
    }
};