class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
       long long int n1=a.size();
       long long int n2=b.size();
       long long int need=n1*x;
       long long int otherhalf=n2*y;
       if (otherhalf>need){
            return false;
       }
       long long int length=min(otherhalf,n1*n2);
       for (int s=0;s<n1;s++){
            if ((s+otherhalf) > need){
                break;
            }
            bool willabletofind=true;
            for (int i=0;i<length;i++){
                if (a[(i+s)%n1] != b[(i)%n2]){
                    willabletofind=false;
                    break;
                }
            }
            if (willabletofind){
                return true;
            }
       }
       return false;
    }
};