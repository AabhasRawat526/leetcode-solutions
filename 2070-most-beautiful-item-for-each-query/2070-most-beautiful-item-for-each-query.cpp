class Solution {
public:

int binarysearch(vector<vector<int>> &items,int queryprice){

    int left=0;
    int right=items.size()-1;
    int maximumbeauty=0;
    while(left<=right){
        int mid=left+(right-left)/2;
        if (items[mid][0]>queryprice){
            right=mid-1;
        }
        else {
            maximumbeauty=max(maximumbeauty,items[mid][1]);
            left=mid+1;
        }
    }
    return maximumbeauty;
}

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        int m=queries.size();
        sort(items.begin(),items.end());
        vector<int> result(m);
        int maxbeauty=items[0][1];
        for (int i=1;i<n;i++){
            maxbeauty=max(maxbeauty,items[i][1]);
            items[i][1]=maxbeauty;
        }

        for (int i=0;i<m;i++){
            int queryprice=queries[i];
            result[i]=binarysearch(items,queryprice);
        }
        return result;
    }
};