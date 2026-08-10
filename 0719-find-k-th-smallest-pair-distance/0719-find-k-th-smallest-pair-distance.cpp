class Solution {
public:


int smallestpairdistance(vector<int>& nums,int distance){
    int i=0;
    int j=1;
    int paircount=0;
    int n=nums.size();
    while(j<n){
        while(abs(nums[j]-nums[i])>distance){
            i++;
        }
        paircount=paircount+(j-i);
        j++;
    }
    return paircount;
}


    int smallestDistancePair(vector<int>& nums, int k) {
        /*
        Brute Force
        int n=nums.size();
        int maxelement=*max_element(nums.begin(),nums.end());
        vector<int> res(maxelement+1);
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int difference=abs(nums[j]-nums[i]);
                res[difference]++;
            }
        }

        for (int i=0;i<maxelement+1;i++){
            k=k-res[i];

            if (k<=0){
                return i;
            }
        }
        return -1;
        */

        /*
        another brute force but this time with the help of partial sorting
        int n=nums.size();
        vector <int> res;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int difference=abs(nums[j]-nums[i]);
                res.push_back(difference);
            }
        }
        nth_element(res.begin(),res.begin()+(k-1),res.end()); // this means put the smallest element in k-1 place..
        return res[k-1];

        */

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums[n-1]-nums[0];
        int res=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            int possible=smallestpairdistance(nums,mid);
            if (possible<k){
                left=mid+1;
            }
            else {
                res=mid;
                right=mid-1;
            }
        }
        return res;
    }
};


/*

A search space + a yes/no condition + monotonic behavior

you should start thinking:

🔥 Binary Search on Answer

① Am I searching for a minimum/maximum value?

↓

② Can I check whether a particular value is possible?

↓

③ If a value is possible, are all larger/smaller values also possible?

↓

If YES → Binary Search is a strong candidate.

For this problem:

Searching for → minimum distance
               
Can check → how many pairs have distance <= mid

Monotonic → if distance X works,
            every distance > X also works

Therefore:

              ↓
       BINARY SEARCH


Core idea: Don't search for the answer directly. Guess an answer with mid, check that guess with possible, then eliminate half the search space.
1. What am I finding?
A minimum / maximum value
2. Can I check a guess?
YES → write a check function
3. Is it monotonic?
FALSE → TRUE → TRUE...
4. Binary Search
Find first valid answer
mid
GUESS
The distance we are testing
possible
JUDGE
Number of pairs with distance ≤ mid
k
TARGET
How many pairs we need
The critical relationship

possible < k → not enough pairs → mid is too small → move RIGHT
possible >= k → enough pairs → mid works → save mid → try LEFT for a smaller answer
Why does possible ≥ k mean mid is valid?

If at least k pairs have distance ≤ mid, then the kth smallest distance must be ≤ mid.
So mid is a valid upper bound, not the final answer yet.

We therefore search for the smallest mid that passes.
Why does this find the exact answer?

Suppose distances produce this condition:

0 1 2 3 4 5 6 7
✗ ✗ ✗ ✗ ✗ ✓ ✓ ✓

Binary search finds the first ✓. That first valid distance is exactly the kth smallest distance.
Remember: paircount NEVER becomes the answer. mid is the guessed distance. paircount only tells us whether that guessed distance is too small or large enough.
Outer loop vs inner function
Outer binary search
left → mid → right

Guesses distances and eliminates impossible ranges.
Inner pair-count function
smallestpairdistance(nums, mid)

Judges the current guessed distance by counting valid pairs.
Example 1 — k = 4
pair distances = 2, 2, 3, 5, 5, 7
Guess 3 → pairs ≤ 3 = 3 → 3 < 4 → too small → go right.

Guess 5 → pairs ≤ 5 = 5 → 5 ≥ 4 → works → save 5 → go left.

Guess 4 → pairs ≤ 4 = 3 → 3 < 4 → too small.

Answer = 5
Example 2 — simple kth smallest
values = 1, 3, 5, 8, 10

Suppose you want the 3rd smallest value. Guess 5. Count how many values are ≤ 5: 3. Since 3 ≥ k, 5 works. Now search smaller. This is the same basic idea: guess → count/check → move left/right.
Example 3 — real-world analogy
Question: What is the minimum speeed needed to finish a job within 8 hours?

mid = guessed speed.
possible = hours needed at that speed.

If hours > 8 → speed too slow → go RIGHT.
If hours ≤ 8 → speed works → try a smaller speed → go LEFT.

Same pattern: guess a value → check it → find the minimum valid value.

mid guesses the answer, check() judges the guess, and binary search finds the smallest guess that passes.”
5 questions to ask yourself in future problems

① Am I searching for a minimum/maximum value?
② Can I guess a value X?
③ Can I efficiently check whether X works?
④ If X works, do larger/smaller values also behave predictably?
⑤ Can I find the first TRUE / last TRUE using binary search?

If YES → strongly consider Binary Search on Answer.


Give feedback
🧠 The shortest version to memorize
I want an answer X
       ↓
I don't know X
       ↓
Guess X = mid
       ↓
Can I check whether mid works?
       ↓
     YES
       ↓
Check(mid)
       ↓
 ┌───────────────┐
 ↓               ↓
FAIL            WORKS
 ↓               ↓
too small       maybe smaller
 ↓               ↓
RIGHT            LEFT
       ↓
Repeat
       ↓
First valid mid = ANSWER
For your Smallest Distance Pair specifically:
mid
 ↓
"Assume this is the distance"
 ↓
paircount
 ↓
"How many pairs have distance <= mid?"
 ↓
paircount < k
 ↓
mid is too small
 ↓
RIGHT

OR

paircount >= k
 ↓
mid is big enough
 ↓
save mid
 ↓
try smaller
 ↓
LEFT
⭐ The sentence I really want you to remember

mid is the guess. paircount is the evidence. Binary search uses that evidence to decide whether the guess should go left or right.

*/