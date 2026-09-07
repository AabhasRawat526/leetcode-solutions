class Solution {
public:

typedef vector<double> V;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // int n=arr.size();
        // priority_queue <vector<double>> pq; // by default it is max heap
        // for (int i=0;i<n-1;i++){
        //     for (int j=i+1;j<n;j++){
        //         double fraction=(double) arr[i]/arr[j];
        //         pq.push(vector<double>{fraction,(double) arr[i],(double) arr[j]});

        //         if(pq.size()>k){
        //             pq.pop();
        //         }
        //     }
        // }
        // auto vec=pq.top();
        // vector<int>res(2);  // size of the vector is 2....
        // res[0]=vec[1];
        // res[1]=vec[2];
        // return res;

        int n=arr.size();

        priority_queue<V,vector<V>,greater<V>> pq;
        for(int i=0;i<n-1;i++){
            double fraction=1.0*arr[i]/arr[n-1];
            pq.push({fraction,(double) i ,(double) n-1});
        }

        int smallest=1;

        while(smallest<k){
            V vec=pq.top();
            pq.pop();
            int i=vec[1];   // we are finding the index here
            int j=vec[2]-1;

            pq.push({1.0*arr[i]/arr[j],(double) i ,(double) j});

            smallest++;
        }

        V vec=pq.top();
        int i=vec[1];
        int j=vec[2];
        return {arr[i],arr[j]};
    }
};