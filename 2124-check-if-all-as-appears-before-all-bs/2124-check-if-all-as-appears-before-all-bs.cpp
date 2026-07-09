class Solution {
public:
    bool checkString(string s) {
        
        /*
        int n=s.size();
        int count=0;
        for (int i=1;i<n;i++){
            if (s[i-1]!=s[i]){
                count++;
            }
        }
        if (count<=1){
            return true;
        }
        return false;
        */

        string s1=s;
        sort(s1.begin(),s1.end());

        if (s==s1){
            return true;
        }
        return false;
    }
};