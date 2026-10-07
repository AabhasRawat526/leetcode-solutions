class Solution {
public:
int n;
unordered_set<string>st;

void solve(string &s,int idx,string &current,int count,int &maxlength){
    if (count<0){    // for pruning logic help to reduce the tc of our code ...
        return;
    }
    if (idx==n){   // base case ..... 
        if (count==0){
            if (current.length()>maxlength){
                maxlength=current.length();
                st.clear();
            }
            if (current.length()==maxlength){
                st.insert(current);
            }
        }
        return;
    }

    if (s[idx]!='(' && s[idx]!=')'){    // for the alphabet case ....
        current.push_back(s[idx]);
        solve(s,idx+1,current,count,maxlength);
        current.pop_back();
        return;
    }
    current.push_back(s[idx]);
    solve(s,idx+1,current,count+(s[idx]=='(' ? +1 : -1),maxlength);  // explore 
    current.pop_back();
    solve(s,idx+1,current,count,maxlength);   // reject move on since we are removing it we can will not increase the count 

}

    vector<string> removeInvalidParentheses(string s) {
        n=s.size();
        st.clear();    // "Forget all results from any previous call; we're solving a fresh input now."
        int maxlength=0;
        string current="";
        solve(s,0,current,0,maxlength);
        return vector<string>(st.begin(),st.end());
    }
};