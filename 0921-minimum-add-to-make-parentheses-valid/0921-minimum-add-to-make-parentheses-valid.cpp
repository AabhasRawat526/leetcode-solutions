class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack <int> st;
        for (int i=0;i<n;i++){
            if (st.empty()){
                st.push(s[i]);
                continue;
            }
            if (st.top()=='(' && s[i]==')'){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.size();
    }
};