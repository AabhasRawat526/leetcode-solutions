class Solution {
public:
    int maxDepth(string s) {
        stack<int>st;
        int n=s.size();
        int result=0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                st.push(s[i]);
                int count=st.size();
                result=max(result,count);
            }
            if (s[i]==')'){
                st.pop();
            }
            else {
                continue;
            }
        }
        return result;
    }
};