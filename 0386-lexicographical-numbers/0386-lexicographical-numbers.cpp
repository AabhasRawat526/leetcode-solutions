class Solution {
public:

void solve(int currentnumber,int n,vector<int> &res){
    if (currentnumber>n){
        return ;
    }
    res.push_back(currentnumber);
    for (int append=0;append<=9;append++){
        int newnumber=(currentnumber*10)+append;
        if (newnumber>n){
            return;
        }

        solve(newnumber,n,res);
    }
}

    vector<int> lexicalOrder(int n) {
       vector<int>res;
       for (int startnum=1;startnum<=9;startnum++){
            solve(startnum,n,res);  // first recursive call 
       }
       return res;
    }
};

// recursion code 