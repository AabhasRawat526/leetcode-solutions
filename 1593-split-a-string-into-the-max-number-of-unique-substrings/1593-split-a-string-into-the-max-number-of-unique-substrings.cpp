class Solution {
public:

void solve(string &s,int idx,unordered_set<string> &s1,int currentcount,int & maxcount){
    if (currentcount+s.size()-idx<maxcount){
        return;
    }
    if (idx==s.size()){
        maxcount=max(currentcount,maxcount);
        return;
    }
    for (int i=idx;i<s.size();i++){
        string found=s.substr(idx,i-idx+1);
        if (s1.find(found)==s1.end()){
            s1.insert(found);
            solve(s,i+1,s1,currentcount+1,maxcount);
            s1.erase(found);
        }
    }
}

    int maxUniqueSplit(string s) {
        int n=s.size();
        int currentcount=0;
        int maxcount=0;
        unordered_set<string> s1;
        solve(s,0,s1,currentcount,maxcount);
        return maxcount;
    }
};