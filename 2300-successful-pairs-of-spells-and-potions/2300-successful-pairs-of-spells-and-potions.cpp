class Solution {
public:

int lowerboundmaking(int left,int right,vector<int>& potions,long long int minpotions){
    while(left<right){
        int mid=(left+right)/2;
        if (potions[mid]>=minpotions){
            right=mid;
        }
        else {
            left=mid+1;
        }
    }
    return right;
}

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        /*
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> answer;
        int maxpotions=potions[m-1];
        for (int i=0;i<n;i++){
            long long int minpotions=ceil((1.0*success)/spells[i]);   // floor division then take the ceil of the function ...

            if (minpotions>maxpotions){
                answer.push_back(0);
                continue;
            }

            int value=lower_bound(potions.begin(),potions.end(),minpotions)-potions.begin(); 
            int count=m-value;
            answer.push_back(count);
        }
        return answer;
        */

        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(),potions.end());
        vector <int> ans;
        long long int maxpotions=potions[m-1];

        for (int i=0;i<n;i++){
            long long int minpotions=ceil(1.0*(success)/spells[i]);

            if (minpotions>maxpotions){
                ans.push_back(0);
                continue;
            }

            int value=lowerboundmaking(0,m-1,potions,minpotions);
            int count=m-value;
            ans.push_back(count);
        }
        return ans;
    }
};



/*

minpotions = 2;     // value we need
value = 1;          // index where 2 is found
count = m - value;  // number of valid potions

lower bound is a c++ stl library which works as a binary search and minpoint value is 2 so it checks the first value which is bigger than or equal to 2 and return the index and it stores the index in the value name variable ...

*/