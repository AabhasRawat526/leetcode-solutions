class Solution {
public:

bool check(int i,int currentsum,int squarenumber){
    if (squarenumber==0){
        return currentsum==i;
    }

    return check(i,currentsum+squarenumber%10,squarenumber/10)||
    check(i,currentsum+squarenumber%100,squarenumber/100)||
    check(i,currentsum+squarenumber%1000,squarenumber/1000)||
    check(i,currentsum+squarenumber%10000,squarenumber/10000);

}

/*

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
        */
        int punishmentNumber(int n) {
            int punishnumber=0;
            for (int i=1;i<=n;i++){
                int square=i*i;
                if (check(i,0,square)){;
                    punishnumber=punishnumber+square;
                }
            }
        return punishnumber;
    }
};