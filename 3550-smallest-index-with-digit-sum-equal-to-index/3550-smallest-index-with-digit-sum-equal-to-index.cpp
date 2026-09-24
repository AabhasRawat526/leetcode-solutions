class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sumofdigit=0;
            int temp=nums[i];
            while(temp>0){
                int digit=temp%10;
                sumofdigit=sumofdigit+digit;
                temp=temp/10;
            }
            if (sumofdigit==i){
                return i;
            }
        }
        return -1;
    }
};