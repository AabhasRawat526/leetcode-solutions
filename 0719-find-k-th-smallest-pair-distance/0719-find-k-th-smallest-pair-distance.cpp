class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        /*
        Brute Force
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
        */

        int n=nums.size();
        vector <int> res;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int difference=abs(nums[j]-nums[i]);
                res.push_back(difference);
            }
        }
        nth_element(res.begin(),res.begin()+(k-1),res.end());
        return res[k-1];
    }
};