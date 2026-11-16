class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if (n<=2){
            return true;
        }
        for (int i=1;i<n-1;i++){
            if (abs(arr[i]-arr[i-1])!=abs(arr[i]-arr[i+1])){
                return false;
            }
        }
        return true;
    }
};