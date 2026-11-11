class Solution {
public:


typedef long long int ll;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll total=0;
        if (cost1 + cost2 <= costBoth){
            return (1LL * need1 * cost1) + (1LL * need2 * cost2);
        }
        ll both= min(need1,need2);
        total= 1LL * both * costBoth;
        need1=need1-both;
        need2=need2-both;
        if (need1 > 0){
            total+= 1LL * need1 * min(cost1,costBoth);
        }
        else if (need2 > 0){
            total+= 1LL * need2 * min(cost2,costBoth);
        }
        return total;
    }
};