class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=knowledge.size();
        unordered_map<string,string>f;
        for (int i=0;i<n;i++){
            f[knowledge[i][0]]=knowledge[i][1];
        }
        int i=0;
        string result="";
        while(i<s.size()){
            if (s[i]=='('){
                int j=s.find(')',i+1);
                string temp=s.substr(i+1,j-i-1);
                result+=(f.count(temp)?f[temp]:"?");
                i=j;
            }
            else {
                result.push_back(s[i]);
            }
            i++;
        }
        return result;
    }
};