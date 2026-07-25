class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        stack <int> st;
        for (int i=0;i<n;i++){
            if (st.empty()){
                st.push(s[i]);
                continue;
            }
            if (st.top()>='A' && st.top()<='Z' && s[i]>='a' && s[i]<='z' || st.top()>='a' && st.top()<='z' && s[i]>='A' && s[i]<='Z'){
                if (tolower(st.top())==s[i]){
                    st.pop();
                    continue;
                }
                if (tolower(s[i])==st.top()){
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        string res;
        while(!st.empty()){
            char ans=st.top();
            st.pop();
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};