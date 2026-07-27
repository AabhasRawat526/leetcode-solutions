class Solution {
public:
    int longestValidParentheses(string s) {

        /*
        int n=s.size();
        stack <int> st;
        int length=0;
        st.push(-1);
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty()){
                    st.push(i);
                }
                else {
                    length=max(length,i-st.top());
                }
            }
        }
        return length;

        */

        int left=0;
        int right=0;
        int length=0;
        int n=s.size();
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                left++;
            }
            else {
                right++;
            }
            if (left==right){
                length=max(length,left*2);
            }
            else if (right>left){
                left=0;
                right=0;
            }
        }
        left=0;
        right=0;
        for (int i=n-1;i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else {
                right++;
            }
            if (left==right){
                length=max(length,left*2);
            }
            else if(left>right){
                left=0;
                right=0;
            }
        }
        return length;
    }
};