class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int MOD=1e9+7;
        vector<int> count(32,0);
        for (int & num : nums){
            for (int b=0;b<32;b++){
                if (num & (1<<b)){
                    count[b]++;    // FOUND 1 
                }
            }
        }
        long long int result=0;
        while(k--){
            long long int current=0;
            for (int b=0;b<32;b++){
                if (count[b]>0){
                    count[b]--;
                    current=(current | (1<<b));
                }
            }
            result=(result+(current*current))%MOD;
        }
        return result;
    }
};


/*

Iteration 1: num = 2
Binary: 010
- b = 0: 2 & 1 → 010 & 001 = 000 → false.
- b = 1: 2 & 2 → 010 & 010 = 010 → true, so count[1]++.
- b = 2: 2 & 4 → 010 & 100 = 000 → false.
Now count[1] = 1.
Iteration 2: num = 3
Binary: 011
- b = 0: bit is 1, so count[0]++.
- b = 1: bit is 1, so count[1]++.
- b = 2: bit is 0, so no change.
Now count[0] = 1, count[1] = 2.
Iteration 3: num = 1
Binary: 001
- b = 0: bit is 1, so count[0]++.
- b = 1 and b = 2: bits are 0, so no change.
Final counts:
Bit position	count[b]	Meaning
Bit 0	2	Two numbers have this bit set
Bit 1	2	Two numbers have this bit set
Bit 2	0	No numbers have this bit set

*/