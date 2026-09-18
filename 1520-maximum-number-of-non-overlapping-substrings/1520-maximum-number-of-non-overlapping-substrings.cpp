class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>startindex(26,-1);
        vector<int>endindex(26,0);
        vector<bool>isvalid(26,false);
        vector<string>res;
        int n=s.size();
        // main working of this is code is that it is maintaining the start index from where it is starting and it is also updating the end index if it is occuring more than one time ...
        for (int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(startindex[idx]==-1){
                startindex[idx]=i;
            }
            endindex[idx]=i;
        }
        // now the main wokring of this part of code is to extend the window and also to check whether we can take that character or not 
        for (int c=0;c<26;c++){
            if (startindex[c]==-1){
                continue;
            }
            isvalid[c]=true;
            // checking whether we can take element or not is it valid or not.
            for (int i=startindex[c];i<=endindex[c];i++){
                if (startindex[s[i]-'a']<startindex[c]){
                    isvalid[c]=false;
                    break;
                }
                // here in this we are extending our window..
                endindex[c]=max(endindex[c],endindex[s[i]-'a']); 
            }
        }
        // to check whether it is overlapping or not 
        int lasttakenindex=INT_MAX;
        for (int i=n-1;i>=0;i--){
            int x=s[i]-'a';
            if (!isvalid[x]){
                continue;
            }
            if (i==startindex[x] && endindex[x]<lasttakenindex){
                res.push_back(s.substr(i,endindex[x]-i+1));
                lasttakenindex=i;
            }
        }      
        return res;
    }
};