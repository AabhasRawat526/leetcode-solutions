class Solution {
public:
    bool canAliceWin(int n) {
        int steps=0;
        int take=10;         // total take is 10 as the total step is 10 so total take is 10 and if we choose initally take 10
        while(n>=take){
            n=n-take;
            take=take-1;    // ek maine le liya so that is why we do -- in the take 
            steps++;
        }
        if (steps%2!=0){
            return true;
        }
        return false;
    }
};