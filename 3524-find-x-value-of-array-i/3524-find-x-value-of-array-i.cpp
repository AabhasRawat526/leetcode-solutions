class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> result(k,0);
        vector<long long>previouscount(k,0);
        for (int i=0;i<n;i++){
            // stores till i th element
            vector<long long>currentcount(k,0);

            int currentelement=nums[i]%k;
            currentcount[currentelement]++;
            for (int oldremainder=0;oldremainder<=k-1;oldremainder++){
                int newremainder=((long long)oldremainder*nums[i]%k)%k;
                currentcount[newremainder]+=previouscount[oldremainder];
            }
            previouscount=std::move(currentcount);
            for (int x=0;x<=k-1;x++){
                result[x]+=previouscount[x];
            }
        }
        return result;
    }
};