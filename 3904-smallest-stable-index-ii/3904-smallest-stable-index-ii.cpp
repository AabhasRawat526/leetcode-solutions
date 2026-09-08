class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>minelementindex(n);
        int minvalue=INT_MAX;
        for(int i=n-1;i>=0;i--){
            minvalue=min(minvalue,nums[i]);
            minelementindex[i]=minvalue;  // arr[3]=2 ====>> [1,_,3] yaha pe me array bana raha hu 
        }
        int maxvalue=INT_MIN;
        for (int i=0;i<n;i++){
            maxvalue=max(maxvalue,nums[i]);
            int value=minelementindex[i];  // minvalue=arr[0] minvalue me kya aajayega that is 1 and yaha pe me array ki value ko kisi aur variable me daaal raha hu .....
            if ((maxvalue-value)<=k){  // 
                return i;
            }
        }
        return -1;
    }
};