class Solution {
public:

bool possible(vector<int> & batteries,long long int expected,int count){

    long long int sum=0;

    for (int i=0;i<batteries.size();i++){
        sum=sum+min((long long)batteries[i],expected); // imp concept ...
    }

    if (sum>=expected*count){
        return true;
    }
    return false;

}


    long long maxRunTime(int n, vector<int>& batteries) {
        long long int m=batteries.size();
        long long int totalsum=0;
        for (int i=0;i<m;i++){
            totalsum=totalsum+batteries[i];
        }
        long long int left=*min_element(batteries.begin(),batteries.end());
        long long int right=totalsum/n; // imp tooo
        long long int res=INT_MIN;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if(possible(batteries,mid,n)){
                res=mid;
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        return res;
    }
};