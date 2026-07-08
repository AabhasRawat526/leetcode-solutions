class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size();
        int m=secondList.size();
        vector<vector<int>> res;
        int i=0;
        int j=0;
        while(i<n and j<m){
            int start1=firstList[i][0];
            int end1=firstList[i][1];
            int start2=secondList[j][0];
            int end2=secondList[j][1];
            if (start1<=start2){      //  First interval starts earlier.
                if (end1>=start2){       // Check if they overlap.
                    int s=max(start1,start2);  // intersection formula
                    int e=min(end1,end2);      // intersection formula
                    res.push_back({s,e});
                }
            }
            else {     //  Second interval starts earlier..
                if (end2>=start1){    // check if they overlap..
                    int s=max(start1,start2);  // same intersection formula 
                    int e=min(end1,end2);   // same intersection formula or condition
                    res.push_back({s,e});
                }
            }
            if (end1>end2){
                j++;        // // Second interval ends first, so move j.
            }
            else {
                i++;    //First interval ends first (or both end together), so move i.
            }
        }
        return res;
    }
};