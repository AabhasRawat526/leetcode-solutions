class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char,int>f;
        for(int i=0;i<n;i++){
            f[text[i]]++;
        }
        unordered_map<char,int>f1;
        f1['b']=1;
        f1['a']=1;
        f1['l']=2;
        f1['o']=2;
        f1['n']=1;
        int count=INT_MAX;
        for (auto i:f1){
            char c=i.first;
            int occur=i.second;
            int extra=f[c];
            int minimum=extra/occur;
            count=min(count,minimum);
        }
        return count;
    }
};