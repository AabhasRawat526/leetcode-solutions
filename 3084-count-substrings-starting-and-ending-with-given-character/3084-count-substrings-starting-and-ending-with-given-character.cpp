class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n=s.size();
        long long int count=0;
        for (int i=0;i<n;i++){
            if(s[i]==c){
                count++;
            }
        }
        return (count*(count+1))/2;
    }
};