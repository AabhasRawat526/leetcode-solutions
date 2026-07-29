class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if (k==0){
            return num;
        }
        stack<char> st;

        for (int i=0;i<n;i++){
            while(st.size()>0 && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        string res;
        while(!st.empty()){
            char topper=st.top();
            st.pop();
            res.push_back(topper);
        }
        reverse(res.begin(),res.end());

        if(res==""){
            return "0";
        }
        int m=res.size();
        for (int i=0;i<m;i++){
            if (res.size()>1 && res[0]=='0'){
                res.erase(0,1);
            }
        }
        while (res.size()>0 && k>0){
            res.pop_back();
            k--;
            if(res==""){
                return "0";
            }
        }
        return res;
    }
};