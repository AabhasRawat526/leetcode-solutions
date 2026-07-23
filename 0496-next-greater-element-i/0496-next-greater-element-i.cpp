class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack <int> st;
        vector <int> res(n);
        res[n-1]=-1;
        st.push(nums2[n-1]);
        for (int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if (st.empty()){
                res[i]=-1;
                st.push(nums2[i]);
            }
            else {
                res[i]=st.top();
                st.push(nums2[i]);
            }
        }
        unordered_map<int,int>f;
        for (int i=0;i<n;i++){
            f[nums2[i]]=res[i];
        }
        vector<int> ans;
        for(int x:nums1){
            ans.push_back(f[x]);
        }
        return ans;
    }
};