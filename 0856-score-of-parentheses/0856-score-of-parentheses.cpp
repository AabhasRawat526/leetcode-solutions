class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        stack<int>st;
        st.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }
            else {
                int value=st.top();st.pop();
                int count=max(2*value,1);
                int anothervalue=st.top();st.pop();
                st.push(count+anothervalue);
            }
        }
        return st.top();
    }
};