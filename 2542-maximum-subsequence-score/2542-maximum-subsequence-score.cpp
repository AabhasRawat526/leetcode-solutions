class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> res;
        for (int i=0;i<n;i++){
            res.push_back({nums1[i],nums2[i]});
        }

        auto lambda=[&](auto &p1,auto &p2){
            return p1.second>p2.second;  // Should the first element come before the second element inside the sort it tells me this..
        };

        sort(res.begin(),res.end(),lambda);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long int kSum=0;
        for (int i=0;i<=k-1;i++){
            kSum=kSum+res[i].first;
            pq.push(res[i].first);
        }
        long long int result=kSum*res[k-1].second;
        for (int i=k;i<n;i++){
            kSum=kSum+res[i].first-pq.top();
            pq.pop();
            pq.push(res[i].first);
            long long int res2=kSum*res[i].second;
            result=max(result,res2);
        }
        return result;
    }
};

/*

Should p1 come BEFORE p2

You have:

p1 = {3, 3}
p2 = {2, 4}

We want to sort by .second in descending order.

So we want:

4
3

Therefore:

p2
p1

because:

p2.second = 4
p1.second = 3
3. Now sort() asks us

It asks:

"Should p1 come before p2?"

Currently:

p1 = {3,3}
p2 = {2,4}

We DON'T want p1 first because:

3 < 4

So our answer should be:

NO → false

How do we produce false?

p1.second > p2.second

Substitute:

3 > 4

That's:

false

Perfect! ✅

Therefore:

return p1.second > p2.second;
4. Now try the opposite situation

Suppose:

p1 = {2,4}
p2 = {3,3}

We want:

p1
p2

because:

4
3

Again sort() asks:

Should p1 come before p2?

YES!

So we need:

true

Our comparator:

p1.second > p2.second

becomes:

4 > 3

which is:

true

Perfect! ✅

5. So look at both cases
Case 1
p1 = {3,3}
p2 = {2,4}

Comparator:

p1.second > p2.second

becomes:

3 > 4
false

Therefore:

p2 comes first
Case 2
p1 = {2,4}
p2 = {3,3}

Comparator:

p1.second > p2.second

becomes:

4 > 3
true

Therefore:

p1 comes first

So we get:

4
3

That's descending order. ✅

6. Why NOT p2.second > p1.second?

Let's use the SAME first example:

p1 = {3,3}
p2 = {2,4}

If you write:

return p2.second > p1.second;

Then:

4 > 3

is:

true

Remember what true means?

"YES, p1 should come before p2."

So it would put:

p1
p2

which means:

3
4

That's ascending ❌.

🧠 The easiest way to remember

Whenever you see:

return something;

inside a sort comparator, mentally replace it with:

"Should the first element come before the second element?"

For descending:

return p1.second > p2.second;

Read it as:

"Should p1 come before p2 if p1 has a bigger second value?"

YES → true
NO → false

One final visual

You want:

BIG → SMALL

4
3
2
1

So ask:

Is p1 bigger than p2?

If YES:

p1 > p2
true

→ p1 goes first.

If NO:

p1 > p2
false

→ p2 goes first.

Therefore:

return p1.second > p2.second;

> gives descending order.
< gives ascending order.

*/