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