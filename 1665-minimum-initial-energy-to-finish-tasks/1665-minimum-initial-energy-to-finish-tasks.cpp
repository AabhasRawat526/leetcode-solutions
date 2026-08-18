class Solution {
public:

bool ispossible(vector<long long>& anothertask,long long int mid,int n,vector<long long>& actualenergyrequired){
    int count=0;
    for (int i=0;i<anothertask.size();i++){
        if (mid>=anothertask[i]){
            mid=mid-actualenergyrequired[i];
            count++;
        }
    }
    if (count==n){
        return true;
    }
    return false;
}

    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        auto lambda=[](auto &tasks1,auto &tasks2){
            int diff1=tasks1[1]-tasks1[0];
            int diff2=tasks2[1]-tasks2[0];

            return diff1>diff2;
        };
        sort(tasks.begin(),tasks.end(),lambda);// jiski remaining value zayada hogi usko phele lenge as me us task ko to kar paunga and saath me uske baad chote task ko bhi but agar me aisa nahi karu and choto ko phele kar du to it is not sure ki me uske baad bade walo ko kar paunga....
        vector<long long> anothertask(n);
        vector<long long> actualenergyrequired(n);
        for (int i=0;i<n;i++){
            anothertask[i]=tasks[i][1];
            actualenergyrequired[i]=tasks[i][0];
        }
        int left=1;
        long long int right=10e9;
        long long int res=0;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            if (ispossible(anothertask,mid,n,actualenergyrequired)){
                res=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return res;
    }
};