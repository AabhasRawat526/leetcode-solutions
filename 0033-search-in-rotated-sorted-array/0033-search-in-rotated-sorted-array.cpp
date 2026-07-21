class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int guess=(low+high)/2;
            if (nums[guess]==target){
                return guess;
            }
            // part1 and part2 me divide kar diya array ko guess is in part1
            if (nums[guess]>nums[n-1]){
                // part1 ke according kara hai sab 
                if (nums[guess]<target){
                    low=guess+1;
                }
                else {
                    if (nums[0]>target){
                        low=guess+1;
                    }
                    else {
                        high=guess-1;
                    }
                }
            }
            else{
                // part2 ke according karenge ab sab guess is in part2.
                if (nums[guess]>target){
                    high=guess-1;
                }
                else {
                    if (nums[n-1]<target){
                        high=guess-1;
                    }
                    else {
                        low=guess+1;
                    }
                }
            }
        }
        return -1;
    }
};