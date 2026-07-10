class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int n=s.size();
        stack<char>st;
        for (int i=0;i<n;i++){
            if (st.empty()){
                st.push(s[i]);
                continue;
            }
            if (st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            char c=st.top();
            st.pop();
            res.push_back(c);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};