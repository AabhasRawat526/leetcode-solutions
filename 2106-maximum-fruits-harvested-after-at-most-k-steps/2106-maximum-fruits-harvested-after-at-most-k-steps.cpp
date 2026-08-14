class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int> position(n);
        vector<int> prefixSum(n);

        for (int i=0;i<n;i++){
            position[i]=fruits[i][0];
            prefixSum[i]=fruits[i][1] + (i==0 ? 0 : prefixSum[i-1]);
        }

        int maxfruits=0;

        for (int d=0;d<=k/2;d++){
            // case 1 when the movement is done in the left

            int i=startPos-d;
            int j=startPos+(k-2*d);

            int left=lower_bound(position.begin(),position.end(),i)-position.begin();
            int right=upper_bound(position.begin(),position.end(),j)-position.begin()-1;

            if (left<=right){
                int leftvalue=prefixSum[right]-(left==0 ? 0 : prefixSum[left-1]);
                maxfruits=max(maxfruits,leftvalue);
            }

            // case two when it is moving to the right

            i=startPos-(k-2*d);
            j=startPos+d;

            left=lower_bound(position.begin(),position.end(),i)-position.begin();
            right=upper_bound(position.begin(),position.end(),j)-position.begin()-1;

            if (left<=right){

                int prefixrightvalue=prefixSum[right] - (left==0 ? 0 : prefixSum[left-1]);

                maxfruits=max(maxfruits,prefixrightvalue);
            }
        }
        return maxfruits;
    }
};