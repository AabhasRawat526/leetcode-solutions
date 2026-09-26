class Solution {
public:

int n;

bool isPalindrome(string &s,int l,int r){
    while(l<r){
        if (s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void solve(string s,int idx,vector<string>& current,vector<vector<string>>& result){
    if(idx==n){
        result.push_back(current);
    }
    for (int i=idx;i<n;i++){
        if (isPalindrome(s,idx,i)){  // starting is idx and ending is the i so l is idx and the r is the i ...
            current.push_back(s.substr(idx,i-idx+1));
            solve(s,i+1,current,result);
            current.pop_back();
        }
    }
}

    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>> result;
        vector<string> current;
        solve(s,0,current,result);
        return result;        
    }
};