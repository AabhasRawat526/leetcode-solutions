class Solution {
public:
    bool checkString(string s) {
        
        /*
        wrong
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
        
        correct but tc is O(nlogn)
        string s1=s;
        sort(s1.begin(),s1.end());

        if (s==s1){
            return true;
        }
        return false;
        */

        int n=s.size();

        int count=0;

        for (int i=0;i<n-1;i++){
            if (s[i]=='b' and s[i+1]=='a'){
                count++;
            }
        }
        if (count==0){
            return true;
        }

        return false;

    }
};