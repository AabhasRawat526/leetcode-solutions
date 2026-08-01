class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
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
    }
};