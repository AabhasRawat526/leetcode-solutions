class Solution {
public:
    int minimumPushes(string word) {
        /*
        piegon hole problem as we have fixed 8 numbers like we have fixed holes in piegon 
        int n=word.size();
        int res=0;
        for (int i=0;i<n;i++){
            res=res+(i/8+1);
        }
        return res;
        */

        int n=word.size();
        for (int i=0;i<n;i++){
            if (n<=8){
                return n;
            }
            if (n<=16){
                return 8+(n-8)*2;
            }
            if (n<=24){
                return 8+16+(n-16)*3;
            }
            if (n<=32){
                return 8+16+24+(n-24)*4;
            }
        }
        return -1;
    }
};