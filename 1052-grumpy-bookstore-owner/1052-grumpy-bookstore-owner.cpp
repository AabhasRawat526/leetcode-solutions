class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int maxsatisfiescustomer=0;
        int currentsatisfiescustomer=0;
        for (int i=0;i<minutes;i++){
            currentsatisfiescustomer=currentsatisfiescustomer+(customers[i] * grumpy[i]);
        }
        maxsatisfiescustomer=currentsatisfiescustomer;
        int i=0;
        int j=minutes;
        while(j<n){
            currentsatisfiescustomer=currentsatisfiescustomer + (customers[j] * grumpy[j]);
            currentsatisfiescustomer=currentsatisfiescustomer - (customers[i] * grumpy[i]);
            maxsatisfiescustomer = max(maxsatisfiescustomer,currentsatisfiescustomer);
            i++;
            j++;
        }
        int totalcustomer=0;
        for (int i=0;i<n;i++){
            if (grumpy[i]==0){
                totalcustomer=totalcustomer + customers[i];
            }
        }
        return totalcustomer + maxsatisfiescustomer;
    }
};