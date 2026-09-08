class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        priority_queue<int>max_heap; // max heap priority queue hoga by default
        priority_queue<int,vector<int>,greater<int>>min_heap;
        sort(queries.begin(),queries.end()); // starting se ho 
        int j=0;
        int usedcount=0;
        for (int i=0;i<n;i++){
            while(j<q && queries[j][0]==i){ // isliye kara kyuki merko starting index bhi dekhna hai ki kya jo element me daal raha hu heap me wo equal hai bhi ya nahi tabhi to wo impact karega us element ko ...
                max_heap.push(queries[j][1]);// ending index ko push kar raha hu me yaha max heap me 
                j++;
            }
            nums[i]=nums[i]-min_heap.size();  // to handle 0 case here basically
            while(nums[i]>0 && !max_heap.empty() && max_heap.top()>=i){
                int ending=max_heap.top();
                max_heap.pop();
                min_heap.push(ending);
                usedcount++;
                nums[i]--;
            }
            if (nums[i]>0){
                return -1;
            }
            while(!min_heap.empty() && min_heap.top()<=i){
                min_heap.pop();
            }
        }
        return q-usedcount;
    }
};