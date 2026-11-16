class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // tc is 0(nlogn)
        /*
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
        */
        int n=arr.size();
        unordered_set<int>f;
        for (int i=0;i<n;i++){
            f.insert(arr[i]);
        }
        int minelement=*min_element(arr.begin(),arr.end());
        int maxelement=*max_element(arr.begin(),arr.end());
        int difference1=(maxelement-minelement)%(n-1);
        int difference=(maxelement-minelement)/(n-1);
        if (difference1!=0){
            return false;
        }
        int i=0;
        while(i<n){
            int element=minelement+i*difference;
            if (f.find(element)==f.end()){
                return false;
            }
            i++;
        }
        return true;
    }
};