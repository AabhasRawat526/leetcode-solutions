class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        char op='+';
        int number=0;
        stack <int> st;
        for (int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=(number*10)+(s[i]-'0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i==n-1){
                 if (op=='+'){
                    st.push(number);
                }
                else if (op=='-'){
                    st.push(-number);
                }
                else if (op=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*number);
                }
                else if (op=='/'){
                    int top=st.top();
                    st.pop();
                    st.push(top/number);
                }
                op=s[i];
                number=0;
            }
        }
        int ans=0;
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        return ans;
    }
};