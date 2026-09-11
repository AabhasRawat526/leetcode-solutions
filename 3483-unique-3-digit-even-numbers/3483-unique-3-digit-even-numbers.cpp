class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        vector<int>digit(10,0);
        int ans=0;
        for (int number:digits){
            digit[number]++;
        }
        // for last digit number
        for (int i=0;i<=9;i++){
            if (i%2!=0 || digit[i]<=0){
                continue;
            }
            else {
                digit[i]--;
            }
            // for middle digit number
            for (int j=0;j<=9;j++){
                if(digit[j]<=0){
                    continue;
                }
                else {
                    digit[j]--;
                }
            // for first digit number
                for (int k=1;k<=9;k++){
                    if (digit[k]<=0){
                        continue;
                    }
                    else{
                        digit[k]--;
                        ans++;
                    }
                    digit[k]++;
                }
                digit[j]++;
            }
            digit[i]++;
        }
        return ans;
    }
};

// tc is 0(1000)
//sc is 0(1)