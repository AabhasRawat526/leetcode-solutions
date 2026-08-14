class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int left=0;
        int ans=0;
        unordered_map<char,int> f;
        for (int right=0;right<n;right++){
            f[s[right]]++;
            while(f[s[right]]>2){
                f[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};