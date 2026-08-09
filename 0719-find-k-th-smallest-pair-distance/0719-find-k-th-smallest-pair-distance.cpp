class Solution {
public:


int smallestpairdistance(vector<int>& nums,int distance){
    int i=0;
    int j=1;
    int paircount=0;
    int n=nums.size();
    while(j<n){
        while(abs(nums[j]-nums[i])>distance){
            i++;
        }
        paircount=paircount+(j-i);
        j++;
    }
    return paircount;
}


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

        /*
        another brute force but this time with the help of partial sorting
        int n=nums.size();
        vector <int> res;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int difference=abs(nums[j]-nums[i]);
                res.push_back(difference);
            }
        }
        nth_element(res.begin(),res.begin()+(k-1),res.end()); // this means put the smallest element in k-1 place..
        return res[k-1];

        */

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            int possible=smallestpairdistance(nums,mid);
            if (possible<k){
                left=mid+1;
            }
            else {
                res=mid;
                right=mid-1;
            }
        }
        return res;
    }
};