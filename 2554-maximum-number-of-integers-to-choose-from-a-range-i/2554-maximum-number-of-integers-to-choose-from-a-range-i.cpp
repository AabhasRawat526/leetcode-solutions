class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st;
        int n1=banned.size();
        int sum=0;
        int count=0;
        for (int i=0;i<n1;i++){
            st.insert(banned[i]);
        }
        for (int i=1;i<=n;i++){
            if (st.find(i)!= st.end()){
                continue;
            }
            else if (sum+i <= maxSum){
                sum=sum+i;
                count++;
            }
            else {
                break;
            }
        }
        return count;
    }
};