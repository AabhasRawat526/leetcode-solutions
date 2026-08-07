class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> a;
        vector <int> b;
        for (int i=0;i<m;i++){
            a.push_back(nums1[i]);
        }
        for (int i=0;i<n;i++){
            b.push_back(nums2[i]);
        }
        vector <int> res(m+n);
        int index=0;
        int i=0;
        int j=0;
        while(i<m and j<n){
            if (a[i]<=b[j]){
                res[index]=a[i];
                i++;
                index++;
            }
            else{
                res[index]=b[j];
                j++;
                index++;
            }
        }
        while(i<m){
            res[index]=a[i];
            i++;
            index++;
        }
        while(j<n){
            res[index]=b[j];
            j++;
            index++;
        }
        nums1=res;
    }
};