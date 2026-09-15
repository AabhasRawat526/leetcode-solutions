class Solution {
public:


int findwinnerindex(int n,int k){
    if (n==1){
        return 0; // means the element will be present in the zero index
    }

    int idx=findwinnerindex(n-1,k);
    idx=(idx+k)%n;
    return idx;
}

    int findTheWinner(int n, int k) {
        /*
        vector<int>arr;
        for (int i=1;i<=n;i++){
            arr.push_back(i);
        }
        int i=0;
        while(arr.size()>1){
            int idx=(i+k-1)%arr.size();
            arr.erase(arr.begin()+idx);
            i=idx;
        }
        return arr[0];
        */
        /*
        queue<int> que;
        for (int i=1;i<=n;i++){
            que.push(i);
        }
        while(que.size()>1){  // 0(n)
            for(int i=1;i<=k-1;i++){ // 0(k) so total tc is 0(n*k)
                que.push(que.front()); // pushing k-1 element to the last 
                que.pop(); // popping k-1 element 
            }
            que.pop(); // popping kth element ... that is what we needed...
        }
        return que.front();
        */

        int resultantidx=findwinnerindex(n,k);
        return resultantidx+1;
    }
};

// tc is the 0(n^2) as we are using two loops here like in the while loop i am iterating n times and during the time of the erasing we are also erasing and shifting the elements to the n times so total tc is the 0(n^2);

// sc is the 0(n) as we are creating the new vector 