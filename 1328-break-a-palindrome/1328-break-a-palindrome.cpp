class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if (n==1){
            return "";
        }
        for (int i=0;i<n/2;i++){
            if (palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};


/*

We are NOT required to make the resulting string smaller than the original palindrome.

We are required to find the lexicographically smallest string among all possible valid non-palindromes.

Therefore, aabab is the correct answer.

Compare it with another possible answer, aabba:

aabab < aabba

because at the third position they are equal, but at the fourth position 'a' < 'b'.

Hence, aabab is the smallest valid answer.

*/