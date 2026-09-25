class Solution {
public:
int result=INT_MIN;


void solve(int idx,vector<string>& words,vector<char>& letters,vector<int>& score,int currentscore,unordered_map<char,int>& f){
    result=max(result,currentscore);
    if (idx==words.size()){
        return;
    }
    int j=0;
    unordered_map<char,int>tempfreq=f;
    int tempscore=0;
    while(j<words[idx].size()){
        if (tempfreq.find(words[idx][j])!=tempfreq.end() && tempfreq[words[idx][j]]>0){
            tempscore=tempscore+score[words[idx][j]-'a'];
            tempfreq[words[idx][j]]--;
        }
        else {
            break;
        }
        j++;
    }
    if (j==words[idx].size()){
        solve(idx+1,words,letters,score,currentscore+tempscore,tempfreq); // we have used that word;
    }
    solve(idx+1,words,letters,score,currentscore,f);

    // result=max(result,currentscore);

}

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=letters.size();
        unordered_map<char,int>f;
        for (int i=0;i<n;i++){
            f[letters[i]]++;
        }
        solve(0,words,letters,score,0,f);
        return result;
    }
};