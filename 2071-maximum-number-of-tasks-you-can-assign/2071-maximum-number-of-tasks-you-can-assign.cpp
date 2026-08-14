class Solution {
public:

bool possible(vector<int>& tasks, vector<int>& workers,int pills,int strength,int mid){
    int pillused=0;
    multiset <int> st(workers.begin(),workers.begin()+mid);  // multiset automatically keeps the values sorted in ascending order, while also allowing duplicate values.
    for (int i=mid-1;i>=0;i--){
        auto id = prev(st.end());
        if (*id >= tasks[i]){
            st.erase(id);
        }
        else if (pillused>=pills){
            return false;
        }
        else {
            auto weakworker=st.lower_bound(tasks[i]-strength);
            if (weakworker==st.end()){
                return false;
            }
            pillused++;
            st.erase(weakworker);
        }
    }
    return true;
}


    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size();
        int m=workers.size();
        sort(tasks.begin(),tasks.end());   // ascending order
        sort(workers.begin(),workers.end(), greater<int>());  // descending order
        int left=0;
        int right=min(n,m);
        int result=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possible(tasks,workers,pills,strength,mid)){
                result=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return result;
    }
};