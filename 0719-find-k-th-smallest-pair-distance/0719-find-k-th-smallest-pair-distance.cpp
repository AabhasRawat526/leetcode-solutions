class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n=nums.size();
        int maxelement=*max_element(nums.begin(),nums.end());
        vector<int> res(maxelement+1);
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int difference=abs(nums[j]-nums[i]);
                res[difference]++;
            }
        }

        for (int i=0;i<maxelement+1;i++){
            k=k-res[i];

            if (k<=0){
                return i;
            }
        }
        return -1;
        
    }
};