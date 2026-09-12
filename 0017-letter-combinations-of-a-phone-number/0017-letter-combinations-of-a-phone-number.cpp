class Solution {
public:

void helperfunction(string digit,int idx,vector<string> &ans,string diary,int n,unordered_map<char,string> &f){
    if (idx==n){
        ans.push_back(diary);
        return ;
    }
    string choices=f[digit[idx]];
    for (int i=0;i<choices.size();i++){
        diary.push_back(choices[i]);
        helperfunction(digit,idx+1,ans,diary,n,f);
        diary.pop_back();
    }
}

    vector<string> letterCombinations(string digits) {

        unordered_map<char,string>f;
        int n=digits.size();
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";
        int idx=0;
        string diary="";
        vector<string>ans;
        helperfunction(digits,0,ans,diary,n,f);    // kicking start our recursion problem 
        return ans;
    }
};