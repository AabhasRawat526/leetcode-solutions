class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int m=s.size();
        char maximum1=*max_element(s.begin(),s.end());
        auto id=max_element(s.begin(),s.end());
        s.erase(id);
        char maximum2=*max_element(s.begin(),s.end());
        auto it=max_element(s.begin(),s.end());
        s.erase(it);
        int number1=0;
        int number2=0;
        number1=(number1*10)+maximum1-'0';     // ascii value will get multplied like 0*10+53-48 = 3 53 is ascii value of '3' and 48 is ascii value of '0' 
        number2=(number2*10)+maximum2-'0';   // same goes for this 
        return number1*number2;
    }
};


// tc in terms of string is O(m) and in terms of number it is O(log n).
// Space = O(m)   O(log n)  in terms of numbers 