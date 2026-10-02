class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int i=0;
        int j=0;
        int currentlength=0;
        int maxcost=0;
        while(j<n){
            maxcost=maxcost+abs(s[j]-t[j]);   // expanding the window 
            while(maxcost>maxCost){
                maxcost=maxcost-abs(s[i]-t[i]);
                i++;   // window shrinking 
            }
            currentlength=max(currentlength,j-i+1);
            j++;
        }
        return currentlength;
    }
};