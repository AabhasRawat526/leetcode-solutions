class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<char> st;
        for (int i=0;i<n;i++){
            if (s[i]=='['){
                st.push(s[i]);
            }
            if(st.size()>0 && st.top()=='[' && s[i]==']'){
                st.pop();
            }
        }
        int m=st.size();
        return (m+1)/2;
    }
};


// balanced walo ko pop out karo and jitne bhi [[[ aaye +1 karo and then divide by 2 karo and get answer ...