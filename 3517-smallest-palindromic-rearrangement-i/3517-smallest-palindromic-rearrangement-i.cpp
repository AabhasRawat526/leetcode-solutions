class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        string s1;
        if (n<2){
            return s;
        }
        
        int mid=(n/2);

        sort(s.begin(),s.begin()+mid);   // upto 2 character if the mid is 2 and upto 3 character is the mid is 3..

        for (int i=0;i<mid;i++){
            s[n-i-1]=s[i];
        }

        return s;
    }
};