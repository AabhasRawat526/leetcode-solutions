class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        arr1.push_back(nums[0]);
        vector<int> arr2;
        arr2.push_back(nums[1]);
        vector<int> res;
        int j=0;
        int l=0;
        for (int i=0;i<n-2;i++){
            if (arr1.back()>arr2.back()){
                arr1.push_back(nums[i+2]);
                l++;
            }
            else {
                arr2.push_back(nums[i+2]);
                j++;
            }
        }

        int m=arr1.size();
        for (int a=0;a<m;a++){
            res.push_back(arr1[a]);
        }
        int x=arr2.size();
        for (int b=0;b<x;b++){
            res.push_back(arr2[b]);
        }
        return res;
    }
};