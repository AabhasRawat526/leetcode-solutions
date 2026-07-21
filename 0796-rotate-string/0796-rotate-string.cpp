class Solution {
public:
    bool rotateString(string s, string goal) {
        int n =s.size();
        int m=goal.size();
        if (m!=n){
            return false;
        }
        string s1=s+s;
        if (s1.find(goal) !=string::npos){
            return true;
        }
        return false;
    }
};