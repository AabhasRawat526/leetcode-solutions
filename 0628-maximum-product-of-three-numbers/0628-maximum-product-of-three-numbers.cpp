class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // idea is we can get max product when we multiply first largest*second largest*third largest
        // we can also get max product when we multiply first smallest * second smallest*first largest.
        /*
        tc is 0(n logn)
        int n=nums.size();
        int product=(nums[n-1]*nums[n-2]*nums[n-3]);
        int product1=(nums[0]*nums[1]*nums[n-1]);
        int maximumproduct=max(product,product1);
        return maximumproduct;

        */

        // tc is 0(n) 

        int n=nums.size();

        //vector <int> res=nums;

        vector <int> res;

        // for (int i=0;i<n;i++){
            // res[i]=nums[i];
        // }

        for (int i=0;i<n;i++){
            res.push_back(nums[i]);
        }

        int maximum1=*max_element(res.begin(),res.end());
        auto id=max_element(res.begin(),res.end());
        res.erase(id);

        int maximum2=*max_element(res.begin(),res.end());
        auto it=max_element(res.begin(),res.end());
        res.erase(it);

        int maximum3=*max_element(res.begin(),res.end());
        auto im=max_element(res.begin(),res.end());
        res.erase(im);

        int smallest1=*min_element(nums.begin(),nums.end());
        auto is=min_element(nums.begin(),nums.end());
        nums.erase(is);

        int smallest2=*min_element(nums.begin(),nums.end());
        auto in=min_element(nums.begin(),nums.end());
        nums.erase(in);

        int product1=maximum1*maximum2*maximum3;

        int product2=maximum1*smallest1*smallest2;

        int product=max(product1,product2);

        return product;
    }
};