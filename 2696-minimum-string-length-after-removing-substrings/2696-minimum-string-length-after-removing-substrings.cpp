class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        stack<int> st;
        for (int i=0;i<n;i++){
            if (st.empty()){
                st.push(s[i]);
                continue;
            }
            if (st.top()=='A' && s[i]=='B'){
                st.pop();
                continue;
            }
            if (st.top()=='C' && s[i]=='D'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.size();
    }
};