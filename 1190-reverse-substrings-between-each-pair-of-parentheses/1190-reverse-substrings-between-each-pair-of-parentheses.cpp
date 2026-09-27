class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string result;
        stack<int>st;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                st.push(result.size());
            }
            else if (s[i]==')'){
                int lastlength=st.top();
                st.pop();
                reverse(result.begin()+lastlength,result.end());
            }
            else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};