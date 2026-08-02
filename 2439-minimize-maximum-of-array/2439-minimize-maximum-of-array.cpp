class Solution {
public:

bool isvalid(vector<int>& nums,int expectedmidvalue){
    vector<long long int> arr(nums.begin(),nums.end());
    for (int i=0;i<nums.size()-1;i++){
        if (arr[i]>expectedmidvalue){
            return false;
        }
        else{
            long long int buffer=expectedmidvalue-arr[i];
            arr[i+1]=arr[i+1]-buffer;
        }
    }
    return arr[nums.size()-1]<=expectedmidvalue;
}


    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        while(left<right){
            int mid=(left+right)/2;
            if(isvalid(nums,mid)){
                right=mid;
            }
            else {
                left=mid+1;
            }
        }
        return right;
    }
};