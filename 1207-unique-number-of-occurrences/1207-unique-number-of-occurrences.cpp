class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>f;
        for (int i=0;i<n;i++){
            f[arr[i]]++;
        }
        vector<int>res;
        for (auto &id : f){
            res.push_back(id.second);
        }
        unordered_map<int,int>f1;
        int m=res.size();
        for (int i=0;i<m;i++){
            f1[res[i]]++;
        }
        for (auto &it:f1){
            if (it.second >1){
                return false;
            }
        }
        return true;
    }
};