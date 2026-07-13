class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>f;
        int n=arr1.size();
        int m=arr2.size();
        vector <int> res;
        for (int i=0;i<n;i++){
            f[arr1[i]]++;
        }
        for (int i=0;i<m;i++){
            for (int j=0;j<f[arr2[i]];j++){
                res.push_back(arr2[i]);
            }
            f[arr2[i]]=0;
        }
        vector <int> remainder;
        for (int i=0;i<n;i++){
            if (f[arr1[i]]>0){
                remainder.push_back(arr1[i]);
                f[arr1[i]]--;
            }
        }
        sort(remainder.begin(),remainder.end());
        for (int x:remainder){
            res.push_back(x);
        }
        return res;
    }
};