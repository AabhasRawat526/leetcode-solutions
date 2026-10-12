class Solution {
public:

int n;

void solve(vector<int> & nums,vector<int> & result,vector<vector<int>> & temp,unordered_set<int> & st){
    if (result.size()==nums.size()){
        temp.push_back(result);
        return;
    }

    for (int idx=0;idx<nums.size();idx++){
        if (st.find(nums[idx])==st.end()){
            st.insert(nums[idx]);
            result.push_back(nums[idx]);
            solve(nums,result,temp,st);
            st.erase(nums[idx]);
            result.pop_back();
        }
    }
}

    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        unordered_set<int> st;
        vector<int> result;   // no of elements it stored ....
        vector<vector<int>> temp;   // for permutation it stores.....
        solve(nums,result,temp,st);
        return temp;
    }
};