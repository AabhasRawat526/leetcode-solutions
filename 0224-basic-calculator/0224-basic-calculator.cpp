class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        long long int number=0;
        long long int res=0;
        int sign=1;
        stack <int> st;
        for (int i=0;i<n;i++){
            if(isdigit(s[i])){
                number=(number*10)+s[i]-'0';    // number ban gya yaha pe..
            }
            else if(s[i]=='+'){
                res=res+(number*sign);
                number=0;
                sign=1;
            }
            else if (s[i]=='-'){
                res=res+(number*sign);
                number=0;
                sign=-1;
            }
            else if (s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                number=0;
                sign=1;
            }
            else if (s[i]==')'){    // bracket ke andar wala jo almost ban hone wala hai to waha bhi same chalega operations just like + - and all .......
                res=res+(number*sign);
                number=0;

                int lastsign=st.top();st.pop();
                int lastresult=st.top();st.pop();
                res=res*lastsign;
                res=res+lastresult;
            }
        }
        res=res+(number*sign);
        return res;
    }
};