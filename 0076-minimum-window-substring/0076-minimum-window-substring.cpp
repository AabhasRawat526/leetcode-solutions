class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if (t.length() > n){
            return "";
        }
        unordered_map<char,int>f;
        for (int i=0;i<t.length();i++){
            f[t[i]]++;
        }
        int requiredcount=t.size();
        int currentwindowsize=INT_MAX;
        int i=0;
        int j=0;
        int startingindex=0;
        while(j<n){                     // expanding the window 
            char ch=s[j];
            if (f[ch] > 0){
                requiredcount--;
            }
            f[ch]--;
            while (requiredcount == 0){      // shrinking the windwo
                int currentminwindowsize = j-i+1;
                if (currentwindowsize > currentminwindowsize){
                    currentwindowsize = currentminwindowsize;
                    startingindex = i;
                }
                f[s[i]]++;
                if (f[s[i]] > 0){
                    requiredcount++;
                }
                i++;
            }
            j++;
        }
        if (currentwindowsize == INT_MAX){
            return "";
        }
        return s.substr(startingindex,currentwindowsize); 
    }
};