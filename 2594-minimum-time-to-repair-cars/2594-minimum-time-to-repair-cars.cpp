class Solution {
public:

bool ispossibletorepair(vector<int> & ranks,int cars,long long int mid){
    long long int repaircar=0;
    for (int i=0;i<ranks.size();i++){
        repaircar=repaircar+sqrt(mid/ranks[i]);    // ye to time mil gya 
    }
    if (repaircar>=cars){
        return true;
    }
    return false;
}

    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long int left=0;
        long long int right=1LL*(*max_element(ranks.begin(),ranks.end()))*cars*cars;
        long long int res=-1;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if (ispossibletorepair(ranks,cars,mid)){
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