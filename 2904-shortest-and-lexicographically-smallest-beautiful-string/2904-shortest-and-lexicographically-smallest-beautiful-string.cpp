class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int one=0;
        string result="";
        while(j<n){
            if(s[j]=='1'){
                one++;
            }
            while(one>k || s[i]=='0'){
                if (s[i]=='1'){
                    one--;
                }
                i++;
            }
            if (one==k){
                string temp=s.substr(i,j-i+1);
                if (result.empty() || result.length()>j-i+1 || result.length()== temp.length() && temp<result){
                    result=temp;
                }
            }
            j++;
        }
        return result;
    }
};