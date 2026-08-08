class Solution {
public:

bool canputballs(vector<int> & position,int midpoint,int m){
    int previousball=position[0];
    int countballs=1;
    for (int i=1;i<position.size();i++){
        int currentball=position[i];

        if ((currentball-previousball)>=midpoint){
            countballs++;
            previousball=currentball;
        }

        if (countballs==m){
            break;
        }
    }
    return (countballs==m);
}

    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int res=0;
        int startingpoint=1;
        int endingpoint=position[n-1]-position[0];
        while(startingpoint<=endingpoint){
            int midpoint=startingpoint+(endingpoint-startingpoint)/2;
            if (canputballs(position,midpoint,m)){
                res=midpoint;
                startingpoint=midpoint+1;
            }
            else {
                endingpoint=midpoint-1;
            }
        }
        return res;
    }
};