class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if (is_sorted(s.begin(),s.end())){     // taking 0(n) tc and no sc 
            return 0;
        }

        if (n<=2){
            return -1;
        }

        char minchar=*min_element(s.begin(),s.end());
        char maxchar=*max_element(s.begin(),s.end());

        if (s[0]==minchar || s[n-1]==maxchar){
            return 1;
        }

        char midminchar=*min_element(s.begin()+1,s.end()-1);
        char midmaxchar=*max_element(s.begin()+1,s.end()-1);
        
        if (s[0]>midmaxchar && midminchar > s[n-1]){
            return 3;
        }
        else {
            return 2;
        }
        
        return {};

    }
};