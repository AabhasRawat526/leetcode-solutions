class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int Mod=1e9+7;
        int totalsum=0;
        for (int i:arr){      //
            totalsum=totalsum+i;
        }
        vector<int> original=arr;
        if (k>1){
            arr.insert(arr.end(),original.begin(),original.end());
        }
        int n=arr.size();
        long long int bestfinding=arr[0];
        long long int res=arr[0];
        for (int i=1;i<n;i++){
            long long int v1=bestfinding+arr[i];
            long long int v2=arr[i];
            bestfinding=max(v1,v2);
            res=max(res,bestfinding);
        }
        if (res<0){
            return 0;
        }
        if (k==1){
            return res%Mod;
        }
        if (totalsum>0){
            res=res+(long long) (k-2)*totalsum;
        }
        return res%Mod;
    }
};