class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=ransomNote.size();
        int m=magazine.size();
        unordered_map<char,int>f1;
        unordered_map<char,int>f2;
        for (int i=0;i<n;i++){
            f1[ransomNote[i]]++;
        }
        for (int i=0;i<m;i++){
            f2[magazine[i]]++;
        }
        for (auto i:f1){
            char c=i.first;
            int occurance=i.second;
            int second=f2[c];
            if (occurance>second){
                return false;
            }
        }
        return true;
    }
};