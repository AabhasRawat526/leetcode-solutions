class Solution {
public:

bool possibletodistribute(vector<int>& candies,int mid,long long int k){
    long long int n=0;
    for (int i=0;i<candies.size();i++){
        n=n+(candies[i])/mid;
    }
    if (n<k){
        return false;
    }
    return true;
}

    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int left=1;
        int right=*max_element(candies.begin(),candies.end());
        long long int res=0;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if(possibletodistribute(candies,mid,k)){
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