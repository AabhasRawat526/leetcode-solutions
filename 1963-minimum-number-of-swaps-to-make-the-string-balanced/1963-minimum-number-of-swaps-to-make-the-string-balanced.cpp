class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<char> st;
        for (int i=0;i<n;i++){
            if (st.empty() && s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if (s[i]=='['){
                st.push(s[i]);
                continue;
            }
            if(st.size()>0 && st.top()=='[' && s[i]==']'){
                st.pop();
                continue;
            }
        }
        int m=st.size();
        int mid=m/2;
        return (m+1)/2;
    }
};