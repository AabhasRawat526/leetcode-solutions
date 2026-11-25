class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int>difference(n);
        for (int i=0;i<n;i++){
            difference[i]=capacity[i] - rocks[i];
        }
        sort(difference.begin(),difference.end());
        int count=0;
        for (int i=0;i<n;i++){
            if (difference[i]==0){
                count++;
            }
            else if (additionalRocks >= difference[i]){
                additionalRocks=additionalRocks-difference[i];
                count++;
            }
            else {
                break;
            }
        }
        return count;
    }
};