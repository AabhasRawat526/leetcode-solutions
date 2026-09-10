class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        if (n==1){
            if (word[0]>='A' and word[0]<='Z'){
                return true;
            }
            else if (word[0]>='a' and word[0]<='z'){
                return true;
            }
        }
        for (int i=0;i<n-1;i++){
            if (word[i]>='A' && word[i]<='Z' && word[i+1]>='A' and word[i+1]<='Z'){
            }
            else if (word[i]>='a' and word[i]<='z' && word[i+1]>='a' and word[i+1]<='z'){
            }
            else if (i==0 and word[i]>='A' and word[i]<='Z' && word[i+1]>='a' and word[i+1]<='z'){
            }
            else{
                return false;
            }
        }
        return true;
    }
};