class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<int> st;
        stack<string> st1;
        int currentdigit=0;
        string currentstring="";
        for (int i=0;i<n;i++){
            if (isdigit(s[i])){
                currentdigit=(currentdigit*10)+s[i]-'0';
            }
            else if (s[i]=='['){
                st1.push(currentstring);
                st.push(currentdigit);
                currentdigit=0;
                currentstring="";
            }
            else if (isalpha(s[i])){
                currentstring.push_back(s[i]);
            }
            else if(s[i]==']'){
                int previousdigit=st.top();
                st.pop();
                string previousstring=st1.top();
                st1.pop();
                //currentstring=previousstring+currentstring*previousdigit; used in python
                string repeated="";
                for (int i=0;i<previousdigit;i++){
                    repeated=repeated+currentstring;
                }
                currentstring=previousstring+repeated;
            }
        }
        return currentstring;
    }
};