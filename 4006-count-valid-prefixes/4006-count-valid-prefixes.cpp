class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int count=0;
        int zero=0;
        int one=0;
        int ans;
        for (char ch:s){
            if (ch=='0'){
                zero++;
            }
            else{
                one++;
            }
            ans=abs(zero-one);
            if (ans<=1){
                count++;
            }
        }
        return count;
    }
};