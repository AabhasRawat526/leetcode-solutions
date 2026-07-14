class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int> f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        bool odd=false;
        int count=0;
        for (auto i:f){
            int value=i.second;
            if (value%2==0){
                count=count+value;
            }
            else {
                odd=true;
            }
        }
        if (odd==false){
            return count;
        }

        for (auto i:f){
            int value=i.second;
            if (value%2==1){
                count=count+value-1;
            }
        }
        return count+1;
    }
};