class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack <int> st;
        for (string t:tokens){
            if (t=="+" || t=="-" || t=="*" || t=="/"){
                if (t=="+"){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(a+b);
                }
                else if (t=="-"){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(b-a);
                }
                else if (t=="*"){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(a*b);
                }
                else if (t=="/"){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                    st.push(b/a);
                }
            }
            else {
                st.push(stoi(t));    // to convert string into integer we have this stoi
            }
        }
        return st.top();
    }
};