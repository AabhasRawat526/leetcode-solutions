class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector <int> res;
        int lowdigit=to_string(low).size();
        int highdigit=to_string(high).size();
        for(int length=lowdigit;length<=highdigit;length++){
            for (int start=0;start<=9-length;start++){
                string t=s.substr(start,length);
                int num=stoi(t);
                if (num>=low and num<=high){
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};