class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result;
        int n=seq.size();
        int opencount=0;
        for (int i=0;i<n;i++){
            if (seq[i]=='('){
                opencount++;
                result.push_back(opencount%2);
            }
            else {
                result.push_back(opencount%2);
                opencount--;
            }
        }
        return result;
    }
};