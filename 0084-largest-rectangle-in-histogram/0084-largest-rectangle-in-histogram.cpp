class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack <int> st;
        int maxarea=0;
        for (int i=0;i<=n;i++){
            int Height;
            if (i==n){
                Height=0;
            }
            else {
                Height=heights[i];
            }
            while(!st.empty() && Height<heights[st.top()]){
                int height=heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width=i;
                }
                else {
                    width=i-st.top()-1;
                }
                maxarea=max(maxarea,height*width);
            }
            st.push(i);
        }
        return maxarea;
    }
};


/*

As long as the current bar is greater than or equal to the height at the top index of the stack, we simply push its index.
The moment we encounter a smaller height, we know that the taller bars on the stack cannot extend any further to the right.
So, while the current height is smaller:
Store the height of the top bar.
Pop its index.
Calculate its width:
If the stack is empty → width = i
Otherwise → width = i - st.top() - 1
Compute area = height × width.
Update maxArea.
Keep doing this until the stack is increasing again.
Then push the current index.
At the end, we use a dummy height 0 (i == n) so that every remaining bar in the stack gets processed.

*/