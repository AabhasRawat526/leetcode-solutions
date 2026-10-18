class Solution {
public:

long long int MOD=1e9+7;

vector<vector<long long int>> PascalTriangle;

int solve(vector<int> & nums){
    int n=nums.size();
    if (n<3){
        return 1;
    }
    vector<int> leftarray;
    vector<int> rightarray;
    int root=nums[0];
    for (int i=1;i<n;i++){
        if (nums[i]<root){
            leftarray.push_back(nums[i]);
        }
        else {
            rightarray.push_back(nums[i]);
        }
    }
    long long int x=solve(leftarray) % MOD;
    long long int y=solve(rightarray) % MOD;
    long long int z=PascalTriangle[n-1][leftarray.size()];
    return (((x*y) % MOD) * z) % MOD;
}

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        PascalTriangle.resize(n+1);
        for (int i=0;i<=n;i++){
            PascalTriangle[i]=vector<long long int>(i+1,1);  // PascalTriangle[i] represents the i-th row of Pascal's Triangle.
            //Initially, each row is created with i + 1 elements, and every element is set to 1.
            for (int j=1;j<i;j++){
                PascalTriangle[i][j]=(PascalTriangle[i-1][j]+PascalTriangle[i-1][j-1])%MOD;
            }
        }
        return (solve(nums)-1 + MOD) % MOD;
    }
};