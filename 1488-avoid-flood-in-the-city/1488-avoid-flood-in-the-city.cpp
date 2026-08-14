class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        unordered_map<int,int> lake;  // stores the lakes number and days .
        set<int> st;       // storing the days in which rain does not occur and we can dry the lake and in sorted fashion.....
        vector <int> ans(n,1);

        for (int i=0;i<n;i++){
            if (rains[i]==0){
                st.insert(i);
            }
            else {
                ans[i]=-1;
                if(lake.count(rains[i])){
                    auto it=st.lower_bound(lake[rains[i]]);
                    if (it==st.end()){
                        return {};
                    }
                    int day=*it;
                    ans[day]=rains[i];

                    st.erase(it);
                }
                lake[rains[i]]=i;
            }
        }
        return ans;
    }
};