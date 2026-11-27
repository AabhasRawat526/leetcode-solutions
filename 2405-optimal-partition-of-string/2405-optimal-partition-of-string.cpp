class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int count=0;
        vector<int>lastseen(26,-1);
        int currentstring=0;
        for (int i=0;i<n;i++){
            char ch=s[i];
            if (lastseen[ch-'a'] >= currentstring){
                count++;
                currentstring=i;
            }
            lastseen[ch-'a'] = i;
        }
        return count+1;
    }
};