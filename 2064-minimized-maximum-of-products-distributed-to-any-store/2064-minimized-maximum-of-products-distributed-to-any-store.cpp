class Solution {
public:

bool store(vector<int>& quantities,int mid,int n){
    for (int i=0;i<quantities.size();i++){
       // n=n-ceil((double)quantities[i]/mid);
       n=n-(quantities[i]+mid-1)/mid;
        if (n<0){
            return false;
        }
    }
    return true;
}

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        sort(quantities.begin(),quantities.end());
        int left=1;
        int maxelement=*max_element(quantities.begin(),quantities.end());
        int right=maxelement;
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(store(quantities,mid,n)){
                res=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return res;
    }
};