class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k==1){
            return 'a';
        }
        int n=operations.size();
        long long int operationtype=-1;
        long long int length=1;
        long long int newk=-1;
        for (int i=0;i<n;i++){
            length=length*2;
            if (length>=k){
                operationtype=operations[i];
                newk=k-(length/2);
                break;
            }
        }
        char ch=kthCharacter(newk,operations); // recursive calling ho raha hai yaha pe 
        if (operationtype==0){
            return ch;
        }
        return ch=='z' ? 'a' : ch+1;
    }
};