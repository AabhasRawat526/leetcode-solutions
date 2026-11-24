class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxsize=1;
        for (int i=0;i<n;i++){
            int product=1;
            int lowest=1;
            int greatest=0;   // if i choose gcd as 0 it will be correct but if i choose gcd as 1 it will always return 1 because 1 can divide any number so that is whyyy ......
            for (int j=i;j<n;j++){
                product=product*(nums[j]);
                greatest=gcd(greatest,(long long)nums[j]);
                lowest=lcm(lowest,(long long) nums[j]);
                if (product==greatest*lowest){
                    maxsize=max(maxsize,j-i+1);
                }
                else if (product > greatest*lowest){
                    break;
                }
            }
        }
        return maxsize;
    }
};