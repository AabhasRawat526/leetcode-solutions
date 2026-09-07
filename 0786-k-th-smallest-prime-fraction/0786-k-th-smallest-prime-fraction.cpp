class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue <vector<double>> pq; // by default it is max heap
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                double fraction=(double) arr[i]/arr[j];
                pq.push(vector<double>{fraction,(double) arr[i],(double) arr[j]});

                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        auto vec=pq.top();
        vector<int>res(2);  // size of the vector is 2....
        res[0]=vec[1];
        res[1]=vec[2];
        return res;
    }
};