class Solution {
public:
// tc is 0(n) and sc is 0(1)
    bool sumGame(string num) {
        int n=num.size();
        int leftquestionmark=0;
        int rightquestionmark=0;
        int leftsum=0;
        int rightsum=0;
        for (int i=0;i<n;i++){
            if (num[i]=='?'){
                if (i<n/2){
                    leftquestionmark++;
                }
                else {
                    rightquestionmark++;
                }
            }
            else {
                if (i<n/2){
                    leftsum=leftsum+(num[i]-'0');
                }
                else {
                    rightsum=rightsum+(num[i]-'0');
                }
            }
        }
        int totalquestioncount=leftquestionmark+rightquestionmark;
        if ((totalquestioncount%2)!=0){
            return true;
        }
        int LEFTSUM=2*leftsum + 9*leftquestionmark;

        int RIGHTSUM=2*rightsum + 9*rightquestionmark;

        if (LEFTSUM==RIGHTSUM){
            return false;
        }
        return true;
    }
};