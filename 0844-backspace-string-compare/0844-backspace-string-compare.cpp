class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        stack <int> st;
        for (int i=0;i<n;i++){
            if(st.empty() && s[i]!='#'){
                st.push(s[i]);
                continue;
            }
            if (s[i]=='#' && st.size()>0){   // imp this line
                st.pop();
                continue;
            }
            if (st.empty() && s[i]=='#'){
                st.push(s[i]);
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        int m=t.size();
        stack <int> s1;
        for (int i=0;i<m;i++){
            if(s1.empty() && t[i]!='#'){
                s1.push(t[i]);
                continue;
            }
            if (t[i] =='#' && s1.size()>0){    // imp this line
                s1.pop();
                continue;
            }
            if (s1.empty() && t[i]=='#'){
                s1.push(t[i]);
                s1.pop();
                continue;
            }
            s1.push(t[i]);
        }
        vector<char> res;
        while(!st.empty()){
            char ans=st.top();
            st.pop();
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        vector<char> res1;
        while(!s1.empty()){
            char ans1=s1.top();
            s1.pop();
            res1.push_back(ans1);
        }
        reverse(res1.begin(),res1.end());
        if (res==res1){
            return true;
        }
        return false;
    }
};