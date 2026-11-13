class Solution {
public:
    int minSwaps(vector<int>& nums) {
        /*
        int n=nums.size();
        vector<int>temp(2*n);
        for (int i=0;i<2*n;i++){
            temp[i]=nums[i%n];
        }
        int totalcountone=0;
        for (int i=0;i<n;i++){
            if (nums[i]==1){
                totalcountone++;
            }
        }
        int currentone=0;
        for (int i=0;i<totalcountone;i++){
            if (nums[i]==1){
                currentone++;
            }
        }
        int i=0;
        int j=totalcountone;
        int maxcountone=0;
        while(j<2*n){
            if (temp[j]==1){
                currentone++;
            }
            if (temp[i]==1){
                currentone--;
            }
            maxcountone=max(maxcountone,currentone);
            i++;
            j++;
        }
        return totalcountone - maxcountone;
        */
        int n=nums.size();
        int totalcountone=0;
        int maxcountone=0;
        for (int i=0;i<n;i++){
            if (nums[i]==1){
                totalcountone++;
            }
        }
        int currentcountone=0;
        for (int i=0;i<totalcountone;i++){
            if (nums[i]==1){
                currentcountone++;
            }
        }
        int i=0;
        int j=totalcountone;
        while(j<2*n){
            if (nums[j%n]==1){
                currentcountone++;
            }
            if (nums[i%n]==1){
                currentcountone--;
            }
            maxcountone=max(maxcountone,currentcountone);
            i++;
            j++;
        }
        return totalcountone-maxcountone;
    }
};