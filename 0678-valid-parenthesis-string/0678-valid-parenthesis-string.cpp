class Solution {
public:
//int n; 
//bool solve(string s,int idx,int count){
    /* 
    TLE 
    if (idx==n){
        return (count==0);
    }
    if (count<0){
        return false;
    }
    if (s[idx]=='('){
        return solve(s,idx+1,count=count+1);
    }
    if (s[idx]==')'){
        return solve(s,idx+1,count=count-1);
    }
    if (s[idx]=='*'){
        return solve(s,idx+1,count+1) ||
        solve(s,idx+1,count-1) ||
        solve(s,idx+1,count);
    }
    return true;
}

    bool checkValidString(string s) {
        n=s.size(); 
        return solve(s,0,0);
    */
    bool checkValidString(string s) {
        int n=s.size();
        int mincount=0;
        int maxcount=0;
        for (int i=0;i<n;i++){
            if (s[i]=='('){
                maxcount=maxcount+1;
                mincount=mincount+1;
            }
            else if (s[i]==')'){
                mincount=mincount-1;
                maxcount=maxcount-1;
                if (maxcount<0){
                    return false;
                }
                if (mincount<0){
                    mincount=0;
                }
            }
            else {
                maxcount=maxcount+1;
                mincount=mincount-1;
                if (mincount<0){
                    mincount=0;
                }
                if(maxcount<0){
                    return false;
                }
            }
        }
        return (mincount==0);
    }
};