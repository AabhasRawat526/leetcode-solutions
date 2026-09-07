class Solution {
public:

typedef pair<int,int>p;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // // brute force;
        // int M=1e9+7;
        // int m=nums.size();
        // vector<int> temp;
        // for (int i=0;i<m;i++){
        //     int sum=0;
        //     for (int j=i;j<m;j++){
        //         sum=sum+nums[j];
        //         temp.push_back(sum);
        //     }
        // }

        // sort(temp.begin(),temp.end());
        // long long int res=0;   // here left and right is based on the 1 based indexing not on the 0 based indexing
        // for (int i=left-1;i<=right-1;i++){
        //     res=(res+temp[i])%M;
        // }
        // return res;

        // optimal solution ko by using heap 

        int M=1e9+7;
        int m=nums.size();
        priority_queue<p,vector<p>,greater<p>> pq;
        for (int i=0;i<m;i++){
            pq.push({nums[i],i});
        }
        int result=0;
        for (int count=1;count<=right;count++){
            auto data=pq.top();
            pq.pop();

            int sum=data.first;
            int idx=data.second;

            if (count>=left){
                result=(result+sum)%M;
            }

            int new_idx=idx+1;
            if (new_idx<n){
                int new_sum=sum+nums[new_idx];
                pq.push({new_sum,new_idx});
            }
        }
        return result;
    }
};