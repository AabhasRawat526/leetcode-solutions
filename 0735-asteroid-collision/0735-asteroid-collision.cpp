class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack <int> st;
        for (int i=0;i<n;i++){
            bool alive=true;
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                if (st.top()== -asteroids[i]){
                    alive=false;
                    st.pop();
                    break;
                }
                else if (st.top() < -asteroids[i]){
                    st.pop();
                }
                else {
                    alive=false;
                    break;
                }
            }
            if (alive){
                st.push(asteroids[i]);
            }
        }
        vector<int>ans(st.size());
        for (int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};