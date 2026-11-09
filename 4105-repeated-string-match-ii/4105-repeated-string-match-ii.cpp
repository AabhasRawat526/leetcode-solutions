class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
       long long int n1=a.size();
       long long int n2=b.size();
       long long int need=n1*x;
       long long int otherhalf=n2*y;
       if (otherhalf>need){   // otherhalf mtlb jo hame search karna hai agar search karne wala hi zayada bada ho gya as compared to need need means jisme merko search karna hai so it is not possible so return false....
             return false; 
       }
       long long int length=min(otherhalf,n1*n2);
       for (int s=0;s<n1;s++){    // Starting index where we want to search.
            if ((s+otherhalf) > need){  // otherhalf mtlb jo hame search karna hai agar search karne wala hi zayada bada ho gya as compared to need need means jisme merko search karna hai so it is not possible so return false....
                break;    // otherhalf mtlb jo hame search karna hai agar search karne wala hi zayada bada ho gya as compared to need need means jisme merko search karna hai so it is not possible so return false....
                // terminates the whole loop outer for loop...
            }
            bool willabletofind=true;
            for (int i=0;i<length;i++){
                if (a[(i+s)%n1] != b[(i)%n2]){
                    willabletofind=false;
                    break;    // terminates the inner for loop...
                }
            }
            if (willabletofind){
                return true;
            }
       }
       return false;
    }
};