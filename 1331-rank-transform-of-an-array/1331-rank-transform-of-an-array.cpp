class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector <int> anotherarray=arr;
        int rank=1;
        sort(anotherarray.begin(),anotherarray.end());
        unordered_map<int,int> f;
        int n=arr.size();
        for (int i=0;i<n;i++){
            if (f.find(anotherarray[i])==f.end()){
                f[anotherarray[i]]=rank;
                rank++;
            }
        }
        for (int i=0;i<n;i++){
            arr[i]=f[arr[i]];
        }
        return arr;
    }
};