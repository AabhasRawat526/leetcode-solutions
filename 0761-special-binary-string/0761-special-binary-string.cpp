class Solution {
public:

string solve(string s){
    int sum=0;
    int start=0;
    int n=s.size();
    vector<string>special;
    for (int i=0;i<n;i++){
        sum+=(s[i]=='1')? 1 : -1;
        if (sum==0){
            string inner=s.substr(start+1,i-start-1);
            special.push_back("1"+solve(inner)+"0");
            start=i+1;
        }
    }
    sort(special.begin(),special.end(),greater<string>());
    string result;
    for (string &res:special){
        result+=res;
    }
    return result;
}


    string makeLargestSpecial(string s) {
        return solve(s);
    }
};