class Solution {
public:

bool check(int i,int currentsum,string s,int num){
    if (i==s.length()){
        return currentsum==num;
    }
    if (currentsum>num){
        return false;
    }
    bool possible=false;
    for (int j=i;j<s.length();j++){
        string sub=s.substr(i,j-i+1);
        int val=stoi(sub);
        possible = possible || (check(j+1,currentsum+val,s,num));
        if (possible==true){
            return true;
        }
    }
    return possible;
}

    int punishmentNumber(int n) {
        int sum=0;
        for (int i=1;i<=n;i++){
            int square=i*i;
            string s=to_string(square);
            if (check(0,0,s,i)==true){
                sum=sum+square;
            }
        }
        return sum;
    }
};