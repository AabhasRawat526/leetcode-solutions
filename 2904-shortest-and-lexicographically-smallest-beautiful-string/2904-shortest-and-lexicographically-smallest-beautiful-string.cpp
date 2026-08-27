class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int one=0;
        string result="";
        // tc is 0(n^2)  because of while loop and the substr...
        while(j<n){  // tc is 0(n)
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
                string temp=s.substr(i,j-i+1); // because of substr tc is 0(n)
                if (result.empty() || result.length()>temp.length() || result.length()== temp.length() && temp<result){
                    result=temp;
                }
            }
            j++;
        }
        return result;
    }
};
