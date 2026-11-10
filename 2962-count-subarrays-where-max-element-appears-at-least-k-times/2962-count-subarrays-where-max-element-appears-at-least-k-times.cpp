class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        /*
        long long int result=0;
        int maxelement=*max_element(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        int countmaxelement=0;
        while(j<n){
            if(nums[j]==maxelement){
                countmaxelement++;
            }
            while(countmaxelement >= k){
                result=result+n-j;
                if (nums[i]==maxelement){
                    countmaxelement--;
                }
                i++;
            }
            j++;
        }
        return result;
        */
        // tc is 0(n) and the sc is also 0(n) as we are taking another space 
        long long int result=0;
        vector<int>storemaxelementindex;
        int maxelement=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        for (int i=0;i<n;i++){
            if (nums[i]==maxelement){
                storemaxelementindex.push_back(i);
            }
            if (storemaxelementindex.size() >= k){
                result=result+storemaxelementindex[storemaxelementindex.size()-k]+1;
            }
        }
        return result;
    }
};