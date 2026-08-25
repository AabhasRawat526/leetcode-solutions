class Solution {
public:

int binarySearch(vector<int>& mat,int left,int right){
    int res=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if (mat[mid]==1){
            res=mid;              // index store and number of 1 will be 1 more than the number of index......
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return res+1;
}

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row=mat.size();
        int column=mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq; //max heap 
        for (int i=0;i<row;i++){
            int countone=binarySearch(mat[i],0,column-1);
            pair<int,int>current={countone,i};
            if (pq.size()<k){
                pq.push(current);
                continue;
            }
            if (pq.top()<=current){
                continue;
            }
            else {
                pq.pop();
                pq.push(current);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};