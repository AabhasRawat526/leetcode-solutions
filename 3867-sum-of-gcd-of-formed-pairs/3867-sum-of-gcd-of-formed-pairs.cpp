class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long int n=nums.size();
        int maximum=0;
        vector <int> res;
        for (int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
            res.push_back(gcd(maximum,nums[i]));
        }
        sort(res.begin(),res.end());
        long long int i=0;
        long long int j=n-1;
        long long int sum=0;
        while(i<j){
            sum=sum+gcd(res[i],res[j]);
            i++;
            j--;
        }
        return sum;
    }
};