class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int degreeofstring=0;
        for (int i=0;i<n;i++){
            int index=(i+1);
            int reverse=26-(s[i]-'a');
            degreeofstring=degreeofstring+(index*reverse);
        }
        return degreeofstring;
    }
};